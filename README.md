# PSoC5 VS Code Project
The PSoC5 KITT Scanner Example for Visual Studio Code 

<em>For Windows, Linux, MacOs</em>

This example project is refactored for Visual Studio Code. Project configuration is done by the 'good old' PSoC Creator.<br/>
'Kitt Scanner' uses only a handfull of magnificent UDB blocks. Just connect 8 LED's to Port2 (common ground).<br/><br/>

![Kitt Scanner](../../../assets/blob/main/PSoC5_VS_Creator/Kitt_Scanner.png?raw=true)<br/>

```
Visual Studio Code Project
│
├── .vs
│   └── (Visual Studio Code / project settings)
│
├── build
│   └── (The build output for the project: project.elf & project.hex will go here)
│
├── PSoC_Creator.cydsn
│   └── (PSoC Creator project)
│
└── source
    └── (Location of your source files: main.c, etc.)
```

## Preparation
1. Install [Visual Studio Code](https://code.visualstudio.com/download).
1. Install the OTX-Maestro extension (Sidebar > `Extensions` > search `OTX-Maestro` > `Install`).
1. All necessary tools are included in the [OTX-Maestro Tools](https://github.com/onethinx/OTX-Maestro/releases) package, which bundles the GNU ARM tools, OpenOCD, and more.
   * Download and install OTX-Maestro Tools.
1. Clone or download the project to your local machine.
   * **Hint:** To avoid build issues, keep the project directory path short by placing it close to the root directory.

## First Build and Debug!
1. Open the main project folder in VS Code.
1. Click `Clean-Reconfigure` from the status bar. This will scan the PSoC Creator folder for sources, includes, build options, etc., and include them into the project.
   * If the project wasn't initialized before, it will ask which programmer/debugger to use.
1. Click `Build` or `Build-And-Launch` to build (and launch) your project.

## Notes
1. PSoC Creator is needed for the routing / system setup. A Windows environment is required to run PSoC Creator. PSoC Creator is only needed for the chip configuration (often a one-time setup).
1. OpenOCD and J-Link don't support programming of ECC memory. Make sure the 'Store configuration data in ECC memory' setting in the Design Wide Resources (.cydwr) is disabled.
1. The build process uses Cypress' cyelftool which is officialy built for Windows only. OTX-Maestro tools includes is a rebuilt version for MacOs and Linux. The official C source files can be found [here](https://www.cypress.com/documentation/software-and-drivers/elftool-open-source-foss-packages) or [here](https://github.com/RolfNoot/assets/blob/main/PSoC5_VS_Creator/Infineon-CyElfTool-1.0.1.8.zip_(includes_libelf-0.8.13-patch2)-DevelopmentTools-v01_00-EN.zip?raw=true). Another possibility is to use Wine.
1. PSoC Creator uses CyComponentLibrary.a from the PSoC Creator application folder. The postbuild action copies CyComponentLibrary.a from the PSoC Creator application folder to the project folder.
<br/><br/>
![PSoC5_VS_Creator](../../../assets/blob/main/PSoC5_VS_Creator/VS_Code_Creator.png?raw=true)<br/>
