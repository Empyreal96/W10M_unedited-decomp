// PopNewWakeSource 
 
_BYTE *__fastcall PopNewWakeSource(int a1)
{
  _BYTE *v2; // r0
  _BYTE *v3; // r4

  v2 = (_BYTE *)ExAllocatePoolWithTag(512, 40, 544040269);
  v3 = v2;
  if ( v2 )
  {
    memset(v2, 0, 40);
    *((_DWORD *)v3 + 2) = a1;
  }
  return v3;
}
