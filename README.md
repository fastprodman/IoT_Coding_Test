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
