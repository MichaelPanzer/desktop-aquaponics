**Disclaimer: This project is still a work in progress. I would appricate feedback and ideas to improve but use at your own risk.**

# Build Instructions

## Frame
1. Materials
    1. 2040 aluminum extrusion [Amazon Link](https://www.amazon.com/GUWANJI-Aluminum-1000mm-European-Engraving/dp/B08BCG1FT9?dib=eyJ2IjoiMSJ9.qR8lPGRnkrO7s-z6C8tORLABJlGdUiFrbMxK_KuJuYhsETwuKlVHRPfdBZPNwuYK0l0vZH9icafr54bXMGKJ8rU9n0wkkgwA1Bu8GSxS9ZIcI1Tin0ORPkKQtve_GUX4pO4Jpd0TmdAcmhal09rY4dr5eI7TFgB153MBol1NSPllE0PcqvC4LATKC-jGbK_sFTUfqfTmHTd4ObMbwVPqnlb3XHm31n_SD0qXQpaBeVU.s4c-pu2ByQH2ljzpSSYENu-CTE9YRfsGq414SC2k8F4&dib_tag=se&keywords=2040%2Baluminum%2Bextrusion&qid=1745791186&sr=8-11&th=1)
    2. Corner bracket kit with M5 screws and t-nuts [Amazon Link](https://www.amazon.com/Silver-Corner-Bracket-Aluminum-Extrusion/dp/B0F1B1N5N1?crid=16VYTZMIZ79ZI&dib=eyJ2IjoiMSJ9.0zoT07YU213v3HGuqBDCvWoENb3Uh3TM4_Z0AmtEmBkujJSaCP1bubNmp62RNZi3WOZJrwVVkT2Ig3REQlKgO3puQwHkHkfmYKeduqdO83_OHl2dLRjx_v2snqqXhRhLCX5xB2r5N3YKClDrR9T9a1Ad4FfDgzYXGOFy61MZp0hFRSAyA1jlryCXtPbIiQHNlHNBm4Mq0GswQ3-fhgdHD4W81maJGjPVJ8tU2jdPigWkOqNhA2py24h6vJgst_74UvFjwiyEzFe4eXZDtprX-Sh0X5xvV-bF1X6UqelqfQg.RydpX1lZSGHCtE89JUsukGHk8ne8Km199eXF_IKcF5g&dib_tag=se&keywords=2020+corner+bracket+silver&qid=1745791752&s=industrial&sprefix=2020+corner+bracket+silv%2Cindustrial%2C298&sr=1-10)
2. Create the base

    Cut List:

    2x fish length width - 40mm

    2x fish width
    
    The base should be a rectangle that overhangs the fish tank by 20mm on the right and left side. A few mm wider might be preferable as it gives some extra clearance when installing the tank. 

    
3. Add the vertical supports

    The vertical supports are mounted using the corner brackets and can be any height, just be sure to give enough  space to accommodate all grow beds and lights.

## Grow bed
1. Print both halves of the grow bed (I used 100% infil to avoid leaks but you might be able to get away with less).
2. Glue the bed together with two part epoxy, be sure to apply a liberal amount to the inside in order to avoid leaks.
3. Print the outlet spout and install using 2 m4 screws.
3. Install the COB strip to the bottom of the grow bed with 3 m4 screws.
4. Print the grow bed supports and install them at the height of the bed.
5. Fill the bed with expanded clay pebbles [Amazon Link](https://www.amazon.com/dp/B0CR1S1KM7?ref=ppx_pop_mob_ap_share)

## Electronics
1. Materials
    1. Arduino UNO [Amazon Link](https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6?crid=4EW1HCIBJA1I&dib=eyJ2IjoiMSJ9.GATKPetBfUe5w5-6k_zSKE8QzLINAYGbhDZ9uBCi-pMmN35FFNKzGhNOVEB8ttuO6Ich13OzQR1dmPCba4vCinVGfL9iHzX2HSoWw-jwEVXMylEiIX9Sko0o-EKZWlTZkNd4lhsBb6L6NwrTj36Fg-j4VpWD1KIStqVr_AEvMmgLYjr3Jhs_Q6EOyHmDBvw2pxtRO-Qcm54QbFRhY7kokQiblSgFPwLTATzxAxoT-WI.zfeNF7TAlWz6BUc1HGkR8sU9L781wAtbj4iQoo0ocfs&dib_tag=se&keywords=arduino+uno&qid=1745792436&sprefix=arduino+uno%2Caps%2C285&sr=8-1)
    2. Prototype Shield [Amazon Link](https://www.amazon.com/dp/B0BNLFXXGV?ref=ppx_pop_mob_ap_share&th=1)
    3. 5v DC-DC buck converter [Aliexpress Link](https://www.aliexpress.us/item/3256806299955878.html?spm=a2g0o.order_list.order_list_main.22.379418025KtPlN&gatewayAdapt=glo2usa)
    4. 5v water pump [Aliexpress Link](https://www.aliexpress.us/item/3256805952358877.html?spm=a2g0o.order_list.order_list_main.17.379418025KtPlN&gatewayAdapt=glo2usa)
    5. 3W led driver module [Amazon Link](https://www.amazon.com/Driver-Constant-Current-Control-Dimming/dp/B0CGVYYLKZ/ref=sr_1_4?crid=3G5SYCTNR8UDB&dib=eyJ2IjoiMSJ9.wtEpYM1yRroDSWxWw5KBAdFXqoRvQvgpNcZt_QX1c16dmgZPloWZ6nbMmLi9tAN4RE9eQBGMHlHb8Ju5BoR15L3AYt7ExyzZlCSQwt2lRYMVXTwbYqrgk6cAWlFZWaRQMmVNGMFYJIN01s3SrCVXIUklyqkpVP6Z2MQMwTNq5AoKljdWlLlWfq8ySNgW9fUWZ_xEFsEi0crk-OOY4bPg9OKJ5HWBgXTRKMvIYYE3f3ruKqYUfttN0P09Nrv-fppROAAp5QMJXHRuLfOmzFHmQnW7ftMeENsHkTsEGY5F9Bs.km8W4f6V5jBGLfQLTl5Zxjtze2jf92vS0yjaxtsSVAw&dib_tag=se&keywords=3W+5-35V+LED+Driver+700mA+PWM+Dimming+DC+to+DC+Step-Down+Constant+Current&qid=1745792808&s=industrial&sprefix=%2Cindustrial%2C565&sr=1-4)
    6. Bridgelux EB Series COB module [Digikey Link](https://www.digikey.com/en/products/detail/bridgelux/BXEB-L0280Z-35E1000-C-B3/7907665)
    7. 1307 RTC Module [Amazon Link](https://www.amazon.com/Ximimark-DS1307-AT24C32-Module-Arduino/dp/B07TVMVDDP?&linkCode=sl1&tag=zlufy-20&linkId=ada792ca489cc91801611fdefc5786f5&language=en_US&ref_=as_li_ss_tl)
    7. Mosfet [Digikey Lin](https://www.digikey.com/en/products/detail/nexperia-usa-inc/PSMN1R2-30YLC-115/2674281)
    8. 270 ohm Resistor
    9. 12k ohm Resistor
    10. 1N4001 Diode
    11. 10nf capacitor 
    8. Power Supply: Use a 19.5v barrel-styple laptop charger with appropriate current for the amount of LED modules. 19.5v is pretty common for laptop chargers so you should be able to source something used for cheap. A usb-c pd charger will not work as it relies on communication between the charger and device to determine power level. 
    9. MISC - strip pins, 20-26 ga solid core wire, dupont connectors
2. Solder the components to create the circuit shown in the diagram. (DIAGRAM TO BE ADDED LATER)

## Final assembly

1. Install the shield on the Arduino UNO and mount to the frame
2. Wire the pump, COB strips, and power supply to the circuit
3. Configure the arduino program
    1. Modify the timePoints array to create the lighting profile. Over the course of the day, the intensity of the light will be linearly interpolated between the specified points. 
    2. Configure the on and off timing of the pump.
    3. Flash the firmware to the arduino






