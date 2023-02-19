# Automotive-Door-Design-Progect
_**Videos Link:**_ https://drive.google.com/file/d/1gvdRgVYCka-IY4xmsW0AS1ak9fazuvw-/view?usp=share_link 

## **Drivers Used By Both ECU1 and ECU2:**

- _CAN Driver._

- _CanIf Driver._

- _BCM Driver._

- _DIO Driver._

- _PORT Driver._

- _GPT Driver._

## **CAN Message Contents:**

1. **Message Idintifier:** _each message has an identifier (a number represent the priority of the message), the smaller the identifier the higher the priority._

2. **Data Length code:** _it's a bit field (4 bits) decides the number of bytes should be send or received._

3. **Identifier Type:** _Identifier could be 11-bits (standard identifier) or 29-bits (extended identifier)._

4. **Data:** _message data._
