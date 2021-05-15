// PpmFireWmiEvent 
 
int __fastcall PpmFireWmiEvent(int a1, _DWORD *a2, unsigned int a3, int a4)
{
  int v6; // r4
  _BYTE *v7; // r0
  int v8; // r5

  if ( !*(_DWORD *)(a1 + 4) )
    return -1073741823;
  v7 = PpmAllocWmiEvent(a1, a2, a3);
  v8 = (int)v7;
  if ( !v7 )
    return -1073741670;
  if ( a4 )
    memmove((int)&v7[*((_DWORD *)v7 + 14)], a4, a3);
  v6 = IoWMIWriteEvent(v8);
  if ( v6 >= 0 )
    return 0;
  ExFreePoolWithTag(v8);
  return v6;
}
