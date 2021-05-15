// IoFreePoDeviceNotifyList 
 
_BYTE *__fastcall IoFreePoDeviceNotifyList(_BYTE *result)
{
  _BYTE *v1; // r4
  _BYTE *v2; // r5
  int v3; // r6

  v1 = result;
  if ( *result )
  {
    v2 = result + 16;
    v3 = 5;
    do
    {
      IopFreePoDeviceNotifyListHead(v2);
      IopFreePoDeviceNotifyListHead(v2 + 8);
      IopFreePoDeviceNotifyListHead(v2 + 16);
      IopFreePoDeviceNotifyListHead(v2 + 24);
      v2 += 40;
      --v3;
    }
    while ( v3 );
    *v1 = 0;
    result = (_BYTE *)PnpUnlockDeviceActionQueue();
  }
  return result;
}
