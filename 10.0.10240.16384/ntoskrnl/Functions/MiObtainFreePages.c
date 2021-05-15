// MiObtainFreePages 
 
int __fastcall MiObtainFreePages(int result)
{
  int v1; // r5
  _DWORD *v2; // r4

  v1 = *(_DWORD *)(result + 3512);
  v2 = (_DWORD *)result;
  if ( v1 && *(_BYTE *)(v1 + 44) != 1 )
  {
    result = CcNotifyWriteBehind(1);
    if ( (unsigned int)(v2[992] - v2[1030]) >= 0x10 )
      result = KeSetEvent((int)(v2 + 113), 0, 0);
    if ( v2[1030] >= 0x10u )
      result = MiWakeModifiedPageWriter(v2, -1);
    if ( *(_BYTE *)(v1 + 74) )
      result = KeSetEvent(v1 + 72, 0, 0);
  }
  return result;
}
