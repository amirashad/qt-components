cd .
rem -no-obsolete 
echo "updating..."
lupdate libqcomps.pro
linguist qcomps_az.ts qcomps_ru.ts
copy *.qm ..\SafeRegion\i18n 
pause