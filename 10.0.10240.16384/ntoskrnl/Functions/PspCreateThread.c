// PspCreateThread 
 
int __fastcall PspCreateThread(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7, int a8, int a9, char a10, int a11, int a12, _BYTE *a13)
{
  unsigned int v13; // r5
  int v15; // r0
  _DWORD *v16; // r8
  int v17; // r6
  int v18; // r4
  int v19; // r6
  int v20; // r3
  _DWORD *v21; // r4
  unsigned __int8 *v22; // r0
  int v23; // r0
  int v24; // r0
  unsigned int v25; // r1
  __int16 v26; // r3
  unsigned int v27; // r4
  unsigned int v28; // r1
  __int16 v29; // r3
  unsigned int *v30; // r7
  unsigned int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  int v34; // [sp+8h] [bp-1C0h]
  int v35; // [sp+Ch] [bp-1BCh]
  int v36; // [sp+20h] [bp-1A8h] BYREF
  _DWORD *v37; // [sp+24h] [bp-1A4h] BYREF
  int v38; // [sp+28h] [bp-1A0h]
  _BYTE *v39; // [sp+2Ch] [bp-19Ch]
  _DWORD *v40; // [sp+30h] [bp-198h]
  int v41; // [sp+34h] [bp-194h]
  int v42; // [sp+38h] [bp-190h]
  _DWORD *v43; // [sp+3Ch] [bp-18Ch]
  int v44; // [sp+40h] [bp-188h]
  _DWORD *v45; // [sp+44h] [bp-184h]
  int v46; // [sp+48h] [bp-180h]
  int v47[4]; // [sp+50h] [bp-178h] BYREF
  char v48[360]; // [sp+60h] [bp-168h] BYREF

  v43 = a1;
  v44 = a2;
  v40 = (_DWORD *)a6;
  v38 = a8;
  v45 = a7;
  v46 = a3;
  v41 = a9;
  v39 = a13;
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v42 = *(_DWORD *)(v13 + 0x74);
  if ( a8 )
    return sub_8034A8();
  v36 = 0;
  v37 = 0;
  if ( a4 )
  {
    v15 = ObReferenceObjectByHandleWithTag(a4, 2, PsProcessType, 0, 1917023056, &v36, 0);
    v16 = (_DWORD *)v36;
    v17 = v15;
    if ( v15 < 0 )
      return v17;
  }
  else
  {
    ObfReferenceObjectWithTag(a5);
    v16 = (_DWORD *)a5;
  }
  v18 = a11;
  v19 = v38;
  if ( a11 && v38 )
    v18 = 0;
  if ( !v40 && !v18 && ((v16[48] & 0x10) != 0 || (*(_DWORD *)(v42 + 192) & 0x10) != 0) )
    return -1073741790;
  if ( (v16[184] & 1) != 0 )
  {
    v17 = -1073741816;
  }
  else
  {
    v20 = 0;
    v36 = 0;
    if ( (a10 & 1) != 0 )
    {
      v20 = 1;
      v36 = 1;
    }
    if ( (a10 & 2) != 0 )
    {
      v20 |= 2u;
      v36 = v20;
    }
    if ( (a10 & 4) != 0 )
    {
      v20 |= 4u;
      v36 = v20;
    }
    if ( (a10 & 0x10) != 0 )
      v36 = v20 | 0x80;
    --*(_WORD *)(v13 + 308);
    v30 = v16 + 43;
    __pld(v16 + 43);
    v31 = v16[43] & 0xFFFFFFFE;
    do
      v32 = __ldrex(v30);
    while ( v32 == v31 && __strex(v31 + 2, v30) );
    __dmb(0xBu);
    if ( v32 == v31 || ExfAcquireRundownProtection(v16 + 43) )
    {
      ObfReferenceObjectWithTag((int)v16);
      v34 = v18;
      v21 = v40;
      v47[0] = v41;
      v22 = (unsigned __int8 *)PspAllocateThread(v16, v46, 0, v40, v19, v47, v34, a12, &v36, &v37, v39, v48);
      v17 = (int)v22;
      if ( (int)v22 >= 0 )
      {
        ObfDereferenceObjectWithTag((int)v16);
        v23 = PspInsertThread(v37, v16, v41, &v36, v44, v39, v21, v35, (int)v48, v43, v45);
        __pld(v30);
        v17 = v23;
        v24 = *v30 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v25 = __ldrex(v30);
        while ( v25 == v24 && __strex(v24 - 2, v30) );
        if ( v25 != v24 )
          v24 = (int)ExfReleaseRundownProtection((unsigned __int8 *)v16 + 172);
        v26 = *(_WORD *)(v13 + 308) + 1;
        *(_WORD *)(v13 + 308) = v26;
        if ( !v26 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
          KiCheckForKernelApcDelivery(v24);
        ObfDereferenceObject((int)v37);
        return v17;
      }
      __pld(v30);
      v27 = *v30 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v28 = __ldrex(v30);
      while ( v28 == v27 && __strex(v27 - 2, v30) );
      if ( v28 != v27 )
        v22 = ExfReleaseRundownProtection((unsigned __int8 *)v16 + 172);
      v29 = *(_WORD *)(v13 + 308) + 1;
      *(_WORD *)(v13 + 308) = v29;
      if ( !v29 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
        KiCheckForKernelApcDelivery((int)v22);
    }
    else
    {
      v33 = *(_WORD *)(v13 + 308) + 1;
      *(_WORD *)(v13 + 308) = v33;
      if ( !v33 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
        KiCheckForKernelApcDelivery(0);
      v17 = -1073741558;
    }
  }
  ObfDereferenceObjectWithTag((int)v16);
  return v17;
}
