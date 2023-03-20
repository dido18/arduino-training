# Arduino CLI
March 20th 2023


```sql
Arduino Command Line Interface (arduino-cli).

Usage:
  arduino-cli [command]

Examples:
  arduino-cli <command> [flags...]

Available Commands:
  board           Arduino board commands.
  burn-bootloader Upload the bootloader.
  cache           Arduino cache commands.
  compile         Compiles Arduino sketches.
  completion      Generates completion scripts
  config          Arduino configuration commands.
  core            Arduino core operations.
  daemon          Run as a daemon on port: 50051
  debug           Debug Arduino sketches.
  help            Help about any command
  lib             Arduino commands about libraries.
  monitor         Open a communication port with a board.
  outdated        Lists cores and libraries that can be upgraded
  sketch          Arduino CLI sketch commands.
  update          Updates the index of cores and libraries
  upgrade         Upgrades installed cores and libraries.
  upload          Upload Arduino sketches.
  version         Shows version number of Arduino CLI.

Flags:
      --additional-urls strings   Comma-separated list of additional URLs for the Boards Manager.
      --config-file string        The custom config file (if not specified the default will be used).
      --format string             The output format for the logs, can be: text, json, jsonmini, yaml (default "text")
  -h, --help                      help for arduino-cli
      --log-file string           Path to the file where logs will be written.
      --log-format string         The output format for the logs, can be: text, json
      --log-level string          Messages with this level and above will be logged. Valid levels are: trace, debug, info, warn, error, fatal, panic
      --no-color                  Disable colored output.
  -v, --verbose                   Print the logs on the standard output.

```


### Sketch

A Sketch is a NOT the  `.ino` file itself (previously was `.pdi` as `processing ...`).
A sketch is the `folder` with the `.ino` file insides and other extesion files  (e.g., `.h`,`.cpp`,`.md`,) and also an `src` folder.


```sql
Arduino CLI sketch commands.

Usage:
  arduino-cli sketch [command]

Examples:
  arduino-cli sketch new MySketch

Available Commands:
  archive     Creates a zip file containing all sketch files.
  new         Create a new Sketc
```

- `archive` permit to create a zip file to share the sketch
- `new` create a new sketch (a folder with a ino file with the same name)


#### Create a first sketch 
`arduino-cli sketch new firstSteps`

Create a sketch 

```c++

void setup() {
}

void loop() {
}

```


Arduino abstract and simplify the code. The `main` file is something like this.

The user must only implemen the `setup` (executed 1 time) and `loop`
```sql
int main(char *argv){
 setup();
 
 while(1){
    loop();
 }
}
```


#### Compile a sketch

`arduino-cli compile`


``` [note]
FQBN (Fully Qualified Board Name)

The  Fully Qualified Board Name is a triple `<VENDOR>.<ARCHITECTURE>.<BOARD>` e.g.: `arduino:avr:uno`
- vendor: arduino is the vendor of the board
- architecture (platform): avr
- board: is the uno board
```

Compile the first sketch for a board:

```
$ arduino-cli compile -b arduino:avr:uno

Sketch uses 134 bytes (0%) of program storage space. Maximum is 32256 bytes.
Global variables use 0 bytes (0%) of dynamic memory, leaving 2048 bytes for local variables. Maximum is 2048 bytes.


Used platform Version Path                                                     
arduino:avr   1.8.6   /home/dido/.arduino15/packages/arduino/hardware/avr/1.8.6
```

Giving contect (file path) of the sketch 

- ` arduino-cli compile -b arduino:avr:uno -v firstSteps`


#### Config dumps

The `build` folder contains the output of the compile.
It contains a subsfolder for each compile FQBN.

- check the config `arduino-cli config dump`
    ```sh
    ➜  firstSteps git:(main) ✗ arduino-cli config dump                             
    board_manager:
      additional_urls: []
    daemon:
      port: "50051"
    directories:
      data: /home/dido/.arduino15
      downloads: /home/dido/.arduino15/staging
      user: /home/dido/Arduino
    library:
      enable_unsafe_install: false
    logging:
      file: ""
      format: text
      level: info
    metrics:
      addr: :9090
      enabled: true
    output:
      no_color: false
    sketch:
      always_export_binaries: false
    updater:
      enable_notification: true
    ```

By default, the configuration is only in the memory of the cli it is not reading the configuration file.

- create the config file `arduino-cli config init`
- Enable the creation of the `build` folder by `always_export_binaries: true` 


Other configuration files:
- library_index.json
- package.json
- packages/arduino
  - tools: contains the software developed by arduino that are required by the hardware
  - hardware: contains the hardware dependencies
    - avr:
      - cores/arduino: contains the `.c` and `.h` files of the core 
      - platforms.txt: contains the receipts for compile the codes (the `bin` and `elf` file)
      - boards.txt: contains the infor for each boards
      - programmers.txt: bootloader is small firmware that interact ith the uploader tool. the uploaded sends the bin to the bootloader that takes the code and write in the correct place.
    - mbed_portenta
    - samd:


### Install platform 
- `arduino-cli core search portenta` : search for portenta platform
- `arduino-cli core install arduino:mbed_portenta` install the portenta 
  - ` arduino-cli core install PACKAGER:ARCH[@VERSION]`



### List boards 

- `arduino-cli board list`
- ``

Every board  as (potentially) unique id. 
Every usb has a VIP and PID tuple.


```sql
$  lsusb
    
Bus 004 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 003 Device 005: ID 1ea7:0064 SHARKOON Technologies GmbH 2.4G Mouse
Bus 003 Device 004: ID 174f:2454 Syntek Integrated Camera
Bus 003 Device 003: ID 06cb:00fc Synaptics, Inc. 
Bus 003 Device 006: ID 8087:0026 Intel Corp. 
Bus 003 Device 008: ID 2341:0043 Arduino SA Uno R3 (CDC ACM)
Bus 003 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
```

The board pair `<VID,PID>` identify uniquely a device. 
- VID: vendor ID. Arduino is a vendor of manufactured devices.
- PID: Product ID.

The cli calls the builder by sending the PID and VIP, and the builder returns the board.

### Upload to a board

Compile with the `-u` (upload)

`arduino-cli compile -b arduino:avr:uno -u firstSteps -p /dev/ttyACM0 -v`
or 
`arduino-cli upload -b arduino:avr:uno firstSteps -p /dev/ttyACM0 `


### Monitor 
`arduino-cli monitor -p /dev/ttyACM0`

Arduino developed also a `Pluggable monitor` architecture 
It is a protocol developed by arduino that allows to third parties to develop custom serial monitor communication.


### Libraries

```sh
Arduino commands about libraries.

Usage:
  arduino-cli lib [command]

Examples:
  arduino-cli lib install AudioZero
  arduino-cli lib update-index

Available Commands:
  deps         Check dependencies status for the specified library.
  download     Downloads one or more libraries without installing them.
  examples     Shows the list of the examples for libraries.
  install      Installs one or more specified libraries into the system.
  list         Shows a list of installed libraries.
  search       Searches for one or more libraries data.
  uninstall    Uninstalls one or more libraries.
  update-index Updates the libraries index.
  upgrade      Upgrades installed libraries.
```


To know where the stuff are installed
`arduino-cli config dump`

```yaml
directories:
  data: /home/dido/.arduino15
  downloads: /home/dido/.arduino15/staging
  user: /home/dido/Arduino                  // where the sketch and libraries are kept (you can install HW e SW)
```


- `arduino-cli lib search <SOMETHING>` search for missing library
- `arduino-cli lib install <SOMETHING>` install the library in the user folder.

Examples:
- `arduino-cli lib search IOTCloud`
- `arduino-cli lib install ArduinoIoTCloud`



Update a library
- `arduino-cli update`: download the package index 
- `arduino-cli outdated`: check if there are outdated libraries


##### how to develop a new Library?

`arduino-cli compile -b arduino:avr:uno  --library=PATH_OF_LIBRARY_1 --library=PATH_OF_LIBRARY_2 `

Where 
 - `PATH` is the path of the local library 

The output of the compile should show the local library used.

If the library has multiple libraries dependencies use the `--libraries` option.

`arduino-cli compile -b arduino:avr:uno  --libraries=PATH_WITH_MULTIPLE_FOLDERS`

All the libraries in the folder are used during the compilation.




#### Bootloader
You can burn a bootloader to a board.



Other resources:
- arduino lint (https://arduino.github.io/arduino-lint/1.2/) allows to lint sketch/libraries
- https://arduino.github.io/arduino-cli/0.31/