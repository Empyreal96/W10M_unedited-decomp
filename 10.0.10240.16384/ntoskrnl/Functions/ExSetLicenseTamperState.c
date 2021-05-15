// ExSetLicenseTamperState 
 
int __fastcall ExSetLicenseTamperState(int result)
{
  int v1; // r6
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
  int v12; // r7
  int i; // r5
  int v14; // t1
  int v15; // r1
  char *j; // r0
  int v17; // t1
  unsigned int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  int v21; // [sp+0h] [bp-B8h] BYREF
  int v22; // [sp+8h] [bp-B0h] BYREF
  int v23; // [sp+Ch] [bp-ACh]
  int v24; // [sp+10h] [bp-A8h]
  int v25; // [sp+18h] [bp-A0h]
  int v26; // [sp+1Ch] [bp-9Ch]
  int v27; // [sp+20h] [bp-98h]
  int v28; // [sp+24h] [bp-94h]
  int v29; // [sp+28h] [bp-90h]
  int v30; // [sp+2Ch] [bp-8Ch]
  char v31; // [sp+30h] [bp-88h]
  char v32[8]; // [sp+38h] [bp-80h] BYREF
  int v33; // [sp+40h] [bp-78h]
  char v34; // [sp+60h] [bp-58h]
  char v35[8]; // [sp+68h] [bp-50h] BYREF
  int v36; // [sp+70h] [bp-48h]

  v1 = result;
  v2 = 1;
  if ( !result || result == 3 )
    return result;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&dword_922C40, 0, 0);
  v5 = &dword_922C40;
  v6 = v4;
  do
    v7 = __ldrex((unsigned __int8 *)&dword_922C40);
  while ( __strex(v7 | 1, (unsigned __int8 *)&dword_922C40) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_922C40, v4, (unsigned int)&dword_922C40);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  if ( dword_922C44 )
  {
    v9 = sub_6E2570((int)v35, v7, (int)v5, dword_922C44);
    if ( v9 >= 0 )
    {
      v8 = v36;
      goto LABEL_26;
    }
    if ( v9 != -1073741275 || !dword_922C44 )
    {
LABEL_25:
      v8 = 4;
      goto LABEL_26;
    }
    v25 = 0;
    v26 = 0;
    v24 = 4;
    v27 = 0;
    v28 = 0;
    v29 = 0;
    v30 = 0;
    v10 = *(_DWORD *)(dword_922C44 + 4);
    v31 = 1;
    v11 = (unsigned __int8 *)(dword_922C44 + 20);
    if ( dword_922C44 == -20 )
      goto LABEL_23;
    v12 = 0;
    for ( i = 0; v10; --v10 )
    {
      v14 = *v11++;
      i = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v14 - 23737705 + i), 21), 21), 21);
      v12 += v14 - 23737705 + i;
    }
    v22 = v12;
    v23 = i;
    if ( !dword_922C3C )
      goto LABEL_24;
    if ( RtlULongLongToULong(8 * dword_922C3C, (unsigned int)dword_922C3C >> 29, &v21) )
    {
LABEL_23:
      v22 = 0;
      v23 = 0;
      v24 = 4;
    }
    else
    {
      v15 = v21;
      for ( j = byte_922C48; v15; --v15 )
      {
        v17 = (unsigned __int8)*j++;
        i = __ROR4__(-23737705 * __ROR4__(-23737705 * __ROR4__(-23737705 * (v17 - 23737705 + i), 21), 21), 21);
        v12 += v17 - 23737705 + i;
      }
      v22 = v12;
      v23 = i;
    }
LABEL_24:
    memmove((int)v35, (int)&v22, 0x30u);
    v36 = 4;
    sub_6E34A4((int)v35, -1, 0);
    goto LABEL_25;
  }
  v8 = dword_920284;
LABEL_26:
  if ( v8 )
    v2 = 0;
  dword_920284 = v1;
  v33 = v1;
  sub_6E34A4((int)v32, 2, 0);
  v34 = 0;
  sub_6E34A4((int)v32, 32, 0);
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)&dword_922C40);
  while ( __strex(v18 - 1, (unsigned int *)&dword_922C40) );
  if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&dword_922C40);
  result = KeAbPostRelease((unsigned int)&dword_922C40);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(_WORD *)(v19 + 0x134) + 1;
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  if ( v2 )
    result = sub_8A1140(result);
  return result;
}
