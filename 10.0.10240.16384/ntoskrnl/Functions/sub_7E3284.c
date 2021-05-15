// sub_7E3284 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_7E3284(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, _DWORD *a14, int *a15, unsigned int a16, _DWORD *a17)
{
  int v17; // r5
  int v18; // r5
  int v19; // r6
  unsigned int *v20; // r7
  int v21; // r8
  int v22; // r9
  unsigned int v23; // r10
  unsigned int v24; // r0
  unsigned int v25; // t1
  int v26; // r0
  _DWORD v27[3]; // [sp-Ch] [bp-Ch] BYREF

  while ( 1 )
  {
    v25 = *v20;
    v20 += 6;
    v24 = v25;
    if ( *(_DWORD *)(v25 + 16) == v22 )
    {
      v26 = memcmp(v24, v23, 16);
      if ( !v26 )
        break;
    }
    if ( (unsigned int)++v18 >= 4 )
      goto LABEL_12;
  }
  v17 = v21 + 24 * v18;
  if ( !v17 )
LABEL_12:
    __asm { POP.W           {R4-R11,PC} }
  if ( !v19 )
  {
    v26 = DrvDbOpenObjectRegKey((int **)v27[2], 0, 3, v27[1], 1, 0, (int)v27, 0);
    if ( v26 < 0 )
      goto LABEL_10;
    v19 = v27[0];
  }
  DrvDbGetRegValueMappedProperty(v26, v19, v17, a14, a15, a16, a17);
LABEL_10:
  if ( v27[0] )
    ZwClose();
  goto LABEL_12;
}
