// ExGetLicenseTamperState 
 
int __fastcall ExGetLicenseTamperState(int *a1)
{
  int v2; // r8
  unsigned int v3; // r2
  int v4; // r0
  int *v5; // r2
  int v6; // r5
  int v7; // r1
  int v8; // r3
  int v9; // r0
  int v10; // r1
  unsigned __int8 *v11; // lr
  int v12; // r6
  int i; // r5
  int v14; // t1
  int v15; // r1
  char *j; // r0
  int v17; // t1
  unsigned int v18; // r1
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int v23; // [sp+0h] [bp-88h] BYREF
  int v24; // [sp+8h] [bp-80h] BYREF
  int v25; // [sp+Ch] [bp-7Ch]
  int v26; // [sp+10h] [bp-78h]
  int v27; // [sp+18h] [bp-70h]
  int v28; // [sp+1Ch] [bp-6Ch]
  int v29; // [sp+20h] [bp-68h]
  int v30; // [sp+24h] [bp-64h]
  int v31; // [sp+28h] [bp-60h]
  int v32; // [sp+2Ch] [bp-5Ch]
  char v33; // [sp+30h] [bp-58h]
  char v34[8]; // [sp+38h] [bp-50h] BYREF
  int v35; // [sp+40h] [bp-48h]

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
  v5 = &dword_922C40;
  v6 = v4;
  do
    v7 = __ldrex((unsigned int *)&dword_922C40);
  while ( !v7 && __strex(0x11u, (unsigned int *)&dword_922C40) );
  __dmb(0xBu);
  if ( v7 )
    ExfAcquirePushLockSharedEx(&dword_922C40, v4, (unsigned int)&dword_922C40);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( !dword_922C44 )
  {
    v8 = dword_920284;
    goto LABEL_25;
  }
  v9 = sub_6E2570((int)v34, v7, (int)v5, dword_922C44);
  if ( v9 >= 0 )
  {
    v8 = v35;
    goto LABEL_25;
  }
  if ( v9 == -1073741275 && dword_922C44 )
  {
    v27 = 0;
    v28 = 0;
    v26 = 4;
    v29 = 0;
    v30 = 0;
    v31 = 0;
    v32 = 0;
    v10 = *(_DWORD *)(dword_922C44 + 4);
    v33 = 1;
    v11 = (unsigned __int8 *)(dword_922C44 + 20);
    if ( dword_922C44 == -20 )
      goto LABEL_22;
    v12 = 0;
    for ( i = 0; v10; --v10 )
    {
      v14 = *v11++;
      i = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v14 - 23737705 + i), 21), 21), 21);
      v12 += v14 - 23737705 + i;
    }
    v24 = v12;
    v25 = i;
    if ( !dword_922C3C )
      goto LABEL_23;
    if ( RtlULongLongToULong(8 * dword_922C3C, (unsigned __int64)(unsigned int)dword_922C3C >> 29, &v23) )
    {
LABEL_22:
      v24 = 0;
      v25 = 0;
      v26 = 4;
    }
    else
    {
      v15 = v23;
      for ( j = byte_922C48; v15; --v15 )
      {
        v17 = (unsigned __int8)*j++;
        i = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v17 - 23737705 + i), 21), 21), 21);
        v12 += v17 - 23737705 + i;
      }
      v24 = v12;
      v25 = i;
    }
LABEL_23:
    memmove((int)v34, (int)&v24, 0x30u);
    v35 = 4;
    sub_6E34A4((int)v34, -1, 0);
  }
  v8 = 4;
LABEL_25:
  if ( v8 )
    v2 = 1;
  if ( a1 )
    *a1 = v8;
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)&dword_922C40);
  while ( v18 == 17 && __strex(0, (unsigned int *)&dword_922C40) );
  if ( v18 != 17 )
    ExfReleasePushLockShared(&dword_922C40);
  v19 = KeAbPostRelease((unsigned int)&dword_922C40);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = *(_WORD *)(v20 + 0x134) + 1;
  *(_WORD *)(v20 + 308) = v21;
  if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  return v2;
}
