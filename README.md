# Automotive-Door-Design-Progect
_**Videos Link:**_ https://drive.google.com/file/d/1gvdRgVYCka-IY4xmsW0AS1ak9fazuvw-/view?usp=share_link 

## **Drivers Used By Both ECU1 and ECU2:**

1. _CAN Driver._

2. _CanIf Driver._

3. _BCM Driver._

4. _DIO Driver._

5. _PORT Driver._

6. _GPT Driver._

## **CAN Message Contents:**

1. **Message Idintifier:** _each message has an identifier (a number represent the priority of the message), the smaller the identifier the higher the priority._

2. **Data Length code:** _it's a bit field (4 bits) decides the number of bytes should be send or received._

3. **Identifier Type:** _Identifier could be 11-bits (standard identifier) or 29-bits (extended identifier)._

4. **Data:** _message data._
