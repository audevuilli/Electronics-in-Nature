<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.

# Electronics in Nature

This project entitled "Electronics in Nature: Digital Tools to explore our urban natural ecosystem" is a collaboration between Paula Harvey, forest school teacher at [Urban Forest](https://www.urban-forest.org/) and [Aude Vuilliomenet](https:audevuilli.com), PhD Student in the [Connected Environments Lab](https://connected-environments.org/) at [The Bartlett CASA](https://www.ucl.ac.uk/bartlett/casa) in UCL. This project aims to explore environmental sensing technologies and how digital tools can be used to augment the understanding of the ecosystem of an urban park. It focuses primarily on primary and secondary school aged children and seeks to encourage the interest of children for the natural environment as well as to discuss the use of electronics in an outdoor environment. 

This project received support and funding from the [London National Park City](https://www.nationalparkcity.london/) as part of the Ranger program.


## Circuit #1 - LEDs & Moisture Sensor

**Overview**

The first circuit introduces the measurement of moisture content. The circuit uses two nails to measure the moisture of various media, three LEDs to visualise the moisture of the soil (pink for "Dry", green for "Average Moist", and blue for "Very Wet"), and a LCD Screen to read the moisture value in percentage. Once built, the circuit is tested in the mud mixtures created by the children, giving the opportunity to discuss how various types of materials (eg. sand, gravel, grass, saw dust, clay, compost) absorb and retain water. 

**Materials**

Here is the list of components, you will need to build this circuit. Some are the same that we used in circuit #1, some are new. If you need to purcahse any of the components, have a look at The PiHut, eBay, CPC or Amazon, by shopping around you will find reliable one for a fair price. 

- [Arduino Uno Rev3 SMD](https://thepihut.com/products/arduino-uno-rev3-smd)
- [Solderless Breadboard](https://uk.farnell.com/pro-signal/psg-bb-400/breadboard-400-pin-white/dp/2503765)
- [RGB LCD1602 Display](https://thepihut.com/collections/adafruit-lcds-displays/products/rgb-16x2-i2c-lcd-display-3-3v-5v)
- [Various Colours LEDs](https://bit.ly/3vSHqQ8)
- [Two Nails](https://www.centurioneurope.co.uk/65mm-bright-round-wire-nails-250g.html)
- 3x 220 Ohm Resistors
- 1x 10K Ohm Resistor
- 5V StepUp Module(https://bit.ly/3AfxMcW)
- [Latching Push Button Switch](https://bit.ly/3QkzHCw)
- [18650 Battery Case Holder](https://amzn.to/3vYRF5r)
- [18650 Li-Ion 3200mAh Battery](https://www.18650.uk/lg-mh1-18650-battery)
- Some breadbord wires (male-male)
- Soldering Iron

## Circuit #2 - Servo Motor & Temperature & Humidity Sensor

**Overview**

The second circuit introduces the measurement of temperature and humidity. The circuit uses a DHT22 temperature and humidity sensor and a small servo motor. The speed of rotation of the servo motor adjusts according to the values recorded. The higher the temperature, the fastest rotates the motor, and the lower the temperature, the lowest rotates the motor. 

Before testing out the circuit between bright sun and shade, a flower or wind turbine like structure is built to add on top of the servo motor. This object will help to visualise the rotational speed. 

**Materials**

Here is the list of components, you will need to build this circuit. Some are the same that we used in circuit #1, some are new. If you need to purchase any of the components, have a look at The PiHut, eBay, CPC or Amazon. By shopping around, you will find reliable and fair price components.  

New Components
- [Temperature & Humidity Sensor (DHT22)](https://bit.ly/3vTUSn2)
- [Servo Motor SG90](https://bit.ly/3SGqplX)

Same as Circuit #1
- [Arduino Uno Rev3 SMD](https://thepihut.com/products/arduino-uno-rev3-smd)
- [Solderless Breadboard](https://uk.farnell.com/pro-signal/psg-bb-400/breadboard-400-pin-white/dp/2503765)
- [RGB LCD1602 Display](https://thepihut.com/collections/adafruit-lcds-displays/products/rgb-16x2-i2c-lcd-display-3-3v-5v)
- 1x 10K Ohm Resistor
- 5V StepUp Module(https://bit.ly/3AfxMcW)
- [Latching Push Button Switch](https://bit.ly/3QkzHCw)
- [18650 Battery Case Holder](https://amzn.to/3vYRF5r)
- [18650 Li-Ion 3200mAh Battery](https://www.18650.uk/lg-mh1-18650-battery)
- Some breadbord wires (male-male)
- Soldering Iron

## Circuit #3 - Speaker & Light Intensity Photoresistor

**Overview**

The third circuit explores light intensity and our relationship with light and sound. The circuit is built using a photoresistor and a small speaker. Depending on the reading of the sensor (in shade, in full sun), a different melody is being played.  

**Materials**

Here is the list of components, you will need to build this circuit. Some are the same that we used in circuit #1, some are new. If you need to purchase any of the components, have a look at The PiHut, eBay, CPC or Amazon. By shopping around, you will find reliable and fair price components. 

New Components
- [Photoresistor](https://thepihut.com/products/photo-cell-cds-photoresistor)
- [Speaker](https://thepihut.com/products/thin-plastic-speaker-w-wires-8-ohm-0-25w)

Same as Circuit #1
- [Arduino Uno Rev3 SMD](https://thepihut.com/products/arduino-uno-rev3-smd)
- [Solderless Breadboard](https://uk.farnell.com/pro-signal/psg-bb-400/breadboard-400-pin-white/dp/2503765)
- [RGB LCD1602 Display](https://thepihut.com/collections/adafruit-lcds-displays/products/rgb-16x2-i2c-lcd-display-3-3v-5v)
- 1x 220 Ohm Resistors
- 1x 10K Ohm Resistor
- 5V StepUp Module(https://bit.ly/3AfxMcW)
- [Latching Push Button Switch](https://bit.ly/3QkzHCw)
- [18650 Battery Case Holder](https://amzn.to/3vYRF5r)
- [18650 Li-Ion 3200mAh Battery](https://www.18650.uk/lg-mh1-18650-battery)
- Some breadbord wires (male-male)
- Soldering Iron

## Electronics in Nature - Interactive Box

**Overview**

The final circuit include all the three forementioned circuit into one. This is called the "Electronics in Nature" box. This interactive box is built of 6mm plywood that has been pre-cut by a laser cut. Each sensors and actuators have their space around the box and a small solar panel is used to recharge the Li-Ion Battery, which is used to power the circuit. 

**Materials**

The additional materials needed to build the EiN box are listed below. The design file to be used for the laser cut are found in folder 003. 

- 6mm Plywood
- [Mini Solar Panel](https://hobbycomponents.com/power/713-solar-panel-5v-160ma-08w-mini-solar-cell)
- [TP4056 Li-Ion Battery Charging Board](https://amzn.to/3bTvSVX)
-[USB C to USB 3.0 30cm cable](https://amzn.to/3Qxdhh8) 
