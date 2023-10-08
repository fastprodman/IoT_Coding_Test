# Importing STM32 Project into STM32CubeIDE

## Step 1: Launch STM32CubeIDE
- Start STM32CubeIDE on your computer.
- If it's your first time using STM32CubeIDE, you may need to set up a workspace. Choose a directory where your projects will be stored.

## Step 2: Import Project
- Go to the `File` menu at the top left corner of the IDE.
- Hover over `Import...` to reveal the import submenu.
- Select `General` -> `Existing Projects into Workspace`.
- Click on `Next` button.

## Step 3: Select Project
- Click on `Browse...` next to the `Select root directory` field and navigate to the directory containing your existing STM32 project.
- Once the directory is selected, the projects within the directory should appear in the `Projects` list.
- Check the box next to the project you want to import.
- Make sure the `Copy projects into workspace` option is unchecked if you want to keep the project files in their current location, or check it if you want to create a copy in your workspace.

## Step 4: Finalize Import
- Click on `Finish` to complete the import process.
- Your project should now appear in the `Project Explorer` pane on the left side of the IDE.

## Step 5: Build and Run
- Right-click on your imported project in the `Project Explorer`.
- Select `Build Project` to build your project.
- Once the build is successful, click on the `Run` button to upload the code to your STM32 microcontroller and run it.



# Hardware Usage in This Project

## MCU:
- `STM32f103c8t6`

## LED Pins:
You have the option to choose any 2 out of the 4 available pins for LED connections:
- `PA9`
- `PA10`
- `PA11`
- `PA12`

## UART Pins:
- `UART_TX:PA2`
- `UART_RX:PA3`



# Changing Baud Rate in STM32CubeIDE

## Step 1: Access Project Properties
- Right-click on your project in the `Project Explorer` pane.
- Select `Properties` from the context menu.

## Step 2: Navigate to C/C++ General
- Once in `Properties`, navigate to `C/C++ General` -> `Paths and Symbols`.

## Step 3: Change Baud Rate Symbol Value
- Click on the `Symbols` tab.
- Look for the symbol `UART_BAUDRATE` in the list of defined symbols. If it's not visible immediately, you can use the search/filter box to narrow down the list.
- Select the `UART_BAUDRATE` symbol and click on `Edit...`.
  - In the `Value` field, update the baud rate to the desired value (e.g., `115200`).
- Click `OK` to save the new baud rate value.



# Modifying LED Pin Variables in STM32CubeIDE

In this project, `LED_PIN0` and `LED_PIN1` are predefined preprocessor variables representing two pins on Port A out of four available pins (9, 10, 11, and 12). If you wish to assign different pin numbers to `LED_PIN0` and `LED_PIN1`, follow the steps below:

## Step 1: Access Project Properties
- Right-click on your project in the `Project Explorer` pane.
- Select `Properties` from the context menu.

## Step 2: Navigate to C/C++ General
- Once in `Properties`, navigate to `C/C++ General` -> `Paths and Symbols`.

## Step 3: Modify LED Pin Variables
- Click on the `Symbols` tab.
- Look for the symbol `LED_PIN0` in the list of defined symbols. If it's not visible immediately, you can use the search/filter box to narrow down the list.
- Select the `LED_PIN0` symbol and click on `Edit...`.
  - In the `Value` field, update the pin number to your choice (e.g., `9` or `10` or `11` or `12`).
- Click `OK` to save the new pin number.
- Repeat the above sub-steps to modify `LED_PIN1` with your second choice of pin number.
