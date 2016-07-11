cd .
echo "updating..."
lupdate -no-obsolete libqcomps.pro
linguist qcomps_az.ts qcomps_ru.ts
copy *.qm ..\SafeRegion\i18n 
pause