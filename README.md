# Composite Pattern Example
## Graphic
* 請建出右方由兩條`Line`、一個`Rectangle`及兩個`Circles`所組成的`Picture`。
* **draw()** 內只需cout出`Graphic`的名字即可。
* `Picture`內使用vector儲存`Graphics`。
* `Main`將new出所有的圖形，並將所有的圖形組合成一個`Picture`，並呼叫`Picture`的**draw()**，應該會印出`Picture`內的所有components名字。 
* 請記得實作當`Main`對非`Picture`物件呼叫addGraphic()時的**例外處理**。 
* `.cpp`檔和`.h`檔請分開。

![](https://i.imgur.com/cmrMh0x.png)

## File System
* `Directory`內使用**vector**儲存`DirectoryElement`。
* `TxtFile`和`Mp3File`建構的時候需傳入檔名(不包含副檔名)及檔案大小，`Directory`則傳入目錄的名字。 
* **findDirectoryElement(string)**為傳入關鍵字並尋找檔案或目錄，若找得到名稱完全相同的檔案(包含副檔名)或目錄則回傳之，若找不到則回傳`nullptr`。  * 請讓所有的測試案皆通過 (`utTxtFile.h`, `utMp3File.h`, `utDirectory.h`)。
* 其他未說明的項目請參考測試案例。 
* `.cpp`檔和`.h`檔請分開。

![](https://i.imgur.com/4EbDRvN.png)
