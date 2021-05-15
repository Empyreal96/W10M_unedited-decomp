// sub_7FDCEC 
 
int __fastcall sub_7FDCEC(int a1, int a2)
{
  unsigned int v2; // r2
  unsigned int v3; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r1
  unsigned int v6; // r1
  unsigned int *v8; // r4
  _DWORD *v9; // r5
  int (__fastcall *v10)(unsigned int); // [sp-4h] [bp-4h]

  if ( (a2 & 2) != 0 )
    goto LABEL_2;
  __dmb(0xBu);
  do
    v2 = __ldrex(v8);
  while ( v2 == a2 && __strex(a2 - 16, v8) );
  if ( v2 != a2 )
LABEL_2:
    ExfReleasePushLock(v8, a2);
  v3 = KeAbPostRelease((unsigned int)v8);
  __dmb(0xBu);
  v4 = v9 + 830;
  do
  {
    v5 = __ldrex(v4);
    v6 = v5 - 1;
  }
  while ( __strex(v6, v4) );
  __dmb(0xBu);
  if ( !v6 )
    v3 = CmpDeleteHive(v9);
  return v10(v3);
}
