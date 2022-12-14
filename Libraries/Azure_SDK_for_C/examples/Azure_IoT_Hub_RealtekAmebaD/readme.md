---
page_type: sample
description: Connecting a Realtek Ameba D device to Azure IoT using the Azure SDK for Embedded C
languages:
- c
products:
- azure-iot
- azure-iot-pnp
- azure-iot-dps
- azure-iot-hub
---

# How to Setup and Run Azure SDK for Embedded C IoT Hub Client on Realtek AmebaD

- [How to Setup and Run Azure SDK for Embedded C IoT Hub Client on Realtek AmebaD](#how-to-setup-and-run-azure-sdk-for-embedded-c-iot-hub-client-on-realtek-amebad)
  - [Introduction](#introduction)
    - [What is Covered](#what-is-covered)
  - [Prerequisites](#prerequisites)
  - [Setup and Run Instructions](#setup-and-run-instructions)
  - [Certificates - Important to know](#certificates---important-to-know)
    - [Additional Information](#additional-information)
  - [Troubleshooting](#troubleshooting)
  - [Contributing](#contributing)
    - [License](#license)

## Introduction

This is a guide outlining how to run an Azure SDK for Embedded C IoT Hub telemetry sample on an Realtek AmebaD development board.

### What is Covered

- Configuration instructions for the Arduino IDE to compile a sample using the Azure SDK for Embedded C.
- Configuration, build, and run instructions for the IoT Hub telemetry sample.

_The following was run on Windows 10 and Ubuntu Desktop 20.04 environments, with Arduino IDE 1.8.12 and Realtek Boards module 3.0.7._

## Prerequisites

- Have an [Azure account](https://azure.microsoft.com/) created.
- Have an [Azure IoT Hub](https://docs.microsoft.com/azure/iot-hub/iot-hub-create-through-portal) created.
- Have a [logical device](https://docs.microsoft.com/azure/iot-hub/iot-hub-create-through-portal#register-a-new-device-in-the-iot-hub) created in your Azure IoT Hub using the authentication type "Symmetric Key".

    NOTE: Device keys are used to automatically generate a SAS token for authentication, which is only valid for one hour.

- Have the latest [Arduino IDE](https://www.arduino.cc/en/Main/Software) installed.

- [Install the USB](https://www.amebaiot.com/en/ameba-arduino-getting-started/) drivers for the Realtek AmebaD board.

    - You might need to install a USB driver directly from https://www.ftdichip.com/Drivers/VCP.htm

- Have the [Realtek AmebaD board packages](https://www.amebaiot.com/en/amebad-arduino-getting-started/) installed on Arduino IDE. Realtek boards are not natively supported by Arduino IDE, so you need to add them manually.

    - Realtek boards are not natively supported by Arduino IDE, so you need to add them manually.
    - Follow the [instructions](https://www.amebaiot.com/en/amebad-arduino-getting-started/) in the official Realtek AmebaD page.

- Have one of the following interfaces to your Azure IoT Hub set up:
  - [Azure Command Line Interface](https://docs.microsoft.com/cli/azure/install-azure-cli?view=azure-cli-latest) (Azure CLI) utility installed, along with the [Azure IoT CLI extension](https://github.com/Azure/azure-iot-cli-extension).

    On Windows:

      Download and install: https://aka.ms/installazurecliwindows

      ```powershell
      PS C:\>az extension add --name azure-iot
      ```

    On Linux:

      ```bash
      $ curl -sL https://aka.ms/InstallAzureCLIDeb | sudo bash
      $ az extension add --name azure-iot
      ```

      A list of all the Azure IoT CLI extension commands can be found [here](https://docs.microsoft.com/cli/azure/iot?view=azure-cli-latest).

  - The most recent version of [Azure IoT Explorer](https://github.com/Azure/azure-iot-explorer/releases) installed. More instruction on its usage can be found [here](https://docs.microsoft.com/azure/iot-pnp/howto-use-iot-explorer).

  NOTE: This guide demonstrates use of the Azure CLI and does NOT demonstrate use of Azure IoT Explorer.

## Setup and Run Instructions

1. Run the Arduino IDE.

2. Install the Azure SDK for Embedded C library.

    - On the Arduino IDE, go to menu `Sketch`, `Include Library`, `Manage Libraries...`.
    - Search for and install `azure-sdk-for-c`.

3. Open the Realtek AmebaD sample.

    - On the Arduino IDE, go to menu `File`, `Examples`, `azure-sdk-for-c`.
    - Click on `az_realtek_amebaD` to open the sample.

4. Configure the Realtek AmebaD sample.

    Enter your Azure IoT Hub and device information into the sample's `iot_configs.h`.

5. Connect the Realtek AmebaD board to your USB port.

6. On the Arduino IDE, select the board and port.

    - Go to menu `Tools`, `Board` and select `Ameba ARM (32-bits) Boards`/`RTL8722DM/RTL8722CSM`.
    - Go to menu `Tools`, `Port` and select the port to which the microcontroller is connected.

7. Upload the sketch.

    - Go to menu `Sketch` and click on `Upload`.

8. Monitor the MCU (microcontroller) locally via the Serial Port.

    - Go to menu `Tools`, `Serial Monitor`.

        If you perform this step right away after uploading the sketch, the serial monitor will show an output similar to the following upon success:

        ```text
        Connecting to WIFI SSID buckaroo
        .......................WiFi connected, IP address:
        192.168.1.123
        Setting time using SNTP..............................done!
        Current time: Thu May 28 02:55:05 2020
        Client ID: mydeviceid
        Username: myiothub.azure-devices.net/mydeviceid/?api-version=2018-06-30&DeviceClientType=c%2F1.0.0
        Password: SharedAccessSignature sr=myiothub.azure-devices.net%2Fdevices%2Fmydeviceid&sig=placeholder-password&se=1590620105
        MQTT connecting ... connected.
        ```

9. Monitor the telemetry messages sent to the Azure IoT Hub using the connection string for the policy name `iothubowner` found under "Shared access policies" on your IoT Hub in the Azure portal.

    ```bash
    $ az iot hub monitor-events --login <your Azure IoT Hub owner connection string in quotes> --device-id <your device id>
    ```

    <details><summary><i>Expected telemetry output:</i></summary>
    <p>

    ```bash
    Starting event monitor, filtering on device: mydeviceid, use ctrl-c to stop...
    {
        "event": {
            "origin": "mydeviceid",
            "payload": "payload"
        }
    }
    {
        "event": {
            "origin": "mydeviceid",
            "payload": "payload"
        }
    }
    {
        "event": {
            "origin": "mydeviceid",
            "payload": "payload"
        }
    }
    {
        "event": {
            "origin": "mydeviceid",
            "payload": "payload"
        }
    }
    {
        "event": {
            "origin": "mydeviceid",
            "payload": "payload"
        }
    }
    {
        "event": {
            "origin": "mydeviceid",
            "payload": "payload"
        }
    }
    ^CStopping event monitor...
    ```

    </p>
    </details>

## Certificates - Important to know

The Azure IoT service certificates presented during TLS negotiation shall always be validated, on the device, using the appropriate trusted root CA certificate(s).

For the Realtek AmebaD sample, our script `generate_arduino_zip_library.sh` automatically downloads the root certificate used in the United States regions (Baltimore CA certificate) and adds it to the Arduino sketch project.

For other regions (and private cloud environments), please use the appropriate root CA certificate.

### Additional Information

For important information and additional guidance about certificates, please refer to [this blog post](https://techcommunity.microsoft.com/t5/internet-of-things/azure-iot-tls-changes-are-coming-and-why-you-should-care/ba-p/1658456) from the security team.

## Troubleshooting

- The error policy for the Embedded C SDK client library is documented [here](https://github.com/Azure/azure-sdk-for-c/blob/main/sdk/docs/iot/mqtt_state_machine.md#error-policy).
- File an issue via [Github Issues](https://github.com/Azure/azure-sdk-for-c/issues/new/choose).
- Check [previous questions](https://stackoverflow.com/questions/tagged/azure+c) or ask new ones on StackOverflow using the `azure` and `c` tags.

## Contributing

This project welcomes contributions and suggestions. Find more contributing details [here](https://github.com/Azure/azure-sdk-for-c/blob/main/CONTRIBUTING.md).

### License

This Azure SDK for C Arduino library is licensed under [MIT](https://github.com/Azure/azure-sdk-for-c-arduino/blob/main/LICENSE) license.

Azure SDK for Embedded C is licensed under the [MIT](https://github.com/Azure/azure-sdk-for-c/blob/main/LICENSE) license.
