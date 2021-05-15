// ObCaptureObjectStateForDuplication 
 
int ObCaptureObjectStateForDuplication(int a1, int a2, ...)
{
  char v2; // r7
  int v3; // r4
  int v4; // r5
  int v6; // r8
  int v7; // r1
  int v8; // r5
  int v9; // r0
  int v11; // r2
  int v12; // r5
  int v13; // r8
  int v14; // r9
  int v15; // r1
  unsigned int v16; // r3
  int v17; // r3
  unsigned int *v18; // r0
  unsigned int v19; // r4
  unsigned int v20; // r1
  int v21; // r3
  unsigned int *v22; // r0
  unsigned int v23; // r4
  unsigned int v24; // r1
  unsigned int *v25; // r0
  unsigned int v26; // r5
  unsigned int v27; // r4
  int v28; // [sp+10h] [bp-38h] BYREF
  int v29; // [sp+14h] [bp-34h]
  int v30; // [sp+18h] [bp-30h] BYREF
  int v31; // [sp+1Ch] [bp-2Ch] BYREF
  int v32; // [sp+20h] [bp-28h] BYREF
  int v33; // [sp+24h] [bp-24h]
  int varg_r2; // [sp+58h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]
  int v37; // [sp+60h] [bp+18h]
  int *v38; // [sp+64h] [bp+1Ch]
  va_list va1; // [sp+68h] [bp+20h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v37 = va_arg(va1, _DWORD);
  v38 = va_arg(va1, int *);
  v2 = varg_r3;
  v3 = varg_r2;
  v4 = a2;
  v28 = 0;
  v29 = a2;
  v6 = varg_r3 & 2;
  if ( (varg_r3 & 2) == 0 )
  {
    v8 = ObpValidateDesiredAccess(varg_r2);
    if ( v8 < 0 )
      return v8;
    v4 = v7;
  }
  v9 = ObReferenceProcessHandleTable(a1);
  if ( !v9 )
    return sub_7F6AC4();
  v8 = ObpReferenceProcessObjectByHandle(v4, a1, v9, (char)v37, 1967415887, &v31, &v32, &v28);
  if ( v8 < 0 )
  {
    v22 = (unsigned int *)(a1 + 172);
    __pld((void *)(a1 + 172));
    v23 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v24 = __ldrex(v22);
    while ( v24 == v23 && __strex(v23 - 2, v22) );
    if ( v24 != v23 )
      ExfReleaseRundownProtection((unsigned __int8 *)v22);
  }
  else
  {
    if ( (v32 & 4) != 0 )
      v11 = 0;
    else
      v11 = v28;
    v12 = v33;
    if ( v6 )
    {
      v3 = v33;
      varg_r2 = v33;
    }
    v13 = v32 & 0xC;
    if ( (v2 & 8) != 0 )
      v13 |= 8u;
    v14 = v31;
    v15 = v31 - 24;
    v16 = (unsigned int)(v31 - 24) >> 8;
    v38[4] = v11;
    v17 = ObTypeIndexTable[*(unsigned __int8 *)(v15 + 12) ^ (unsigned __int8)v16 ^ (unsigned __int8)ObHeaderCookie];
    v31 = v17;
    if ( (v3 & 0xF0000000) != 0 )
    {
      RtlMapGenericMask((int *)varg_r2a, v17 + 52);
      v3 = varg_r2;
      v17 = v31;
    }
    v30 = (*(_DWORD *)(v17 + 68) | 0x1000000) & v3;
    if ( (v30 & ~v12) != 0 )
    {
      v25 = (unsigned int *)(a1 + 172);
      __pld((void *)(a1 + 172));
      v26 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v27 = __ldrex(v25);
      while ( v27 == v26 && __strex(v26 - 2, v25) );
      if ( v27 != v26 )
        ExfReleaseRundownProtection((unsigned __int8 *)v25);
      ObfDereferenceObjectWithTag(v14);
      v8 = -1073741790;
    }
    else
    {
      v8 = ObpIncrementHandleCountEx(2, &v30, a1, v14, (char)v37, v13, 0);
      v18 = (unsigned int *)(a1 + 172);
      __pld((void *)(a1 + 172));
      v19 = *(_DWORD *)(a1 + 172) & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v20 = __ldrex(v18);
      while ( v20 == v19 && __strex(v19 - 2, v18) );
      if ( v20 != v19 )
        ExfReleaseRundownProtection((unsigned __int8 *)v18);
      if ( v8 < 0 )
      {
        ObfDereferenceObjectWithTag(v14);
      }
      else
      {
        v21 = v29;
        v38[5] = v13;
        v38[1] = v21;
        v38[3] = v30;
        ObfReferenceObjectWithTag(a1);
        *v38 = a1;
        v38[2] = v14;
      }
    }
  }
  return v8;
}
