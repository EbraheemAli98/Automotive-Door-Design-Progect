# Automotive-Door-Design-Progect
_**Videos Link:**_ https://drive.google.com/file/d/1gvdRgVYCka-IY4xmsW0AS1ak9fazuvw-/view?usp=share_link 

**Drivers Shared Between ECU1 and ECU2:**

_1. CAN Driver._

_2. CanIf Driver._

_3. BCM Driver._

_4. DIO Driver._

_5. PORT Driver._

_6. GPT Driver._

**CAN Message Contents:**

_1. Message Idintifier: each message has an identifier (a number represent the priority of the message), the smaller the identifier the higher the priority._

_2. Data Length code: it's a bit field (4 bits) decides the number of bytes should be send or received._

_3. Identifier Type: Identifier could be 11-bits (standard identifier) or 29-bits (extended identifier)._

_4. Data: message data._
