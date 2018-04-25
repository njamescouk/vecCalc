rem @echo off
goto thisOne
:thisOne
echo bare
c:\bin\vecCalc.exe -o testBare.svg test.vecCalc
c:\bin\vecCalc.exe -o bugBare.svg I:\usr\NIK\dev\vecCalc\example\bug.vecCalc
c:\bin\vecCalc.exe -o exampleBare.svg example.vecCalc


echo svg
c:\bin\vecCalc.exe -svg -o test.svg test.vecCalc
c:\bin\vecCalc.exe -svg -o bug.svg I:\usr\NIK\dev\vecCalc\example\bug.vecCalc
c:\bin\vecCalc.exe -svg -o example.svg example.vecCalc

echo dump
c:\bin\vecCalc.exe -d -o test.txt test.vecCalc
c:\bin\vecCalc.exe -d -o bug.txt bug.vecCalc
c:\bin\vecCalc.exe -d -o example.txt example.vecCalc
goto :eof
