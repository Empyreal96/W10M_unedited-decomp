// PiDqQueryAddObjectToResultSet 
 
int __fastcall PiDqQueryAddObjectToResultSet(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r3
  unsigned int *v6; // r2
  unsigned int v7; // r1
  _DWORD var8[5]; // [sp+0h] [bp-8h] BYREF
  int varsC; // [sp+14h] [bp+Ch] BYREF

  var8[4] = a1;
  varsC = a2;
  var8[0] = a4;
  v4 = 0;
  if ( !RtlInsertElementGenericTableAvl(a1 + 36, (int)&varsC, 4, (int)var8) )
    return -1073741670;
  if ( LOBYTE(var8[0]) )
  {
    v5 = varsC;
    __dmb(0xBu);
    v6 = (unsigned int *)(v5 + 4);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 + 1, v6) );
    __dmb(0xBu);
  }
  return v4;
}
