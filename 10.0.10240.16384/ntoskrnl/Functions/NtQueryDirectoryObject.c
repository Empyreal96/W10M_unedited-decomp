// NtQueryDirectoryObject 
 
int __fastcall NtQueryDirectoryObject(int a1, int a2, unsigned int a3, int a4, char a5, _DWORD *a6, unsigned int *a7)
{
  int v9; // r4
  _DWORD *v10; // r2
  unsigned int *v11; // r2
  int v12; // r6
  int v13; // r10
  _BYTE *v14; // r0
  unsigned int v15; // r9
  int v16; // r5
  unsigned int v17; // r2
  _DWORD *v18; // r9
  unsigned int *v19; // r8
  int v20; // r0
  int v21; // r4
  unsigned int v22; // r2
  unsigned int i; // r8
  _DWORD *j; // r4
  _DWORD *v25; // t1
  int v27; // r10
  int v28; // r3
  int v29; // r2
  int v30; // lr
  __int16 v31; // r3
  int v32; // r1
  _DWORD *v33; // lr
  int v34; // r3
  int v35; // r8
  int v36; // r9
  int v37; // r4
  unsigned __int16 *v38; // r6
  unsigned int v39; // t1
  _WORD *v40; // r4
  _WORD *v41; // r4
  unsigned int *v42; // r4
  int v43; // r1
  unsigned int v44; // r0
  unsigned int v45; // r2
  int v46; // r0
  unsigned int v47; // r1
  __int16 v48; // r3
  unsigned int v49; // r3
  int v51; // [sp+Ch] [bp-6Ch]
  int v52; // [sp+10h] [bp-68h]
  int v53; // [sp+10h] [bp-68h]
  unsigned int v54; // [sp+14h] [bp-64h]
  unsigned int v55; // [sp+18h] [bp-60h]
  _DWORD *v56; // [sp+1Ch] [bp-5Ch] BYREF
  int v57; // [sp+20h] [bp-58h]
  int v58; // [sp+24h] [bp-54h]
  _DWORD *v59; // [sp+28h] [bp-50h]
  unsigned int *v60; // [sp+2Ch] [bp-4Ch]
  int v61; // [sp+30h] [bp-48h]
  unsigned int v62; // [sp+34h] [bp-44h]
  int v63; // [sp+38h] [bp-40h]
  _BYTE *v64; // [sp+40h] [bp-38h]
  int v65; // [sp+48h] [bp-30h] BYREF
  int v66; // [sp+4Ch] [bp-2Ch]
  unsigned int v67; // [sp+50h] [bp-28h]
  _BYTE *v68; // [sp+54h] [bp-24h]
  unsigned int *v69; // [sp+58h] [bp-20h]
  int varg_r0; // [sp+80h] [bp+8h]
  int varg_r1; // [sp+84h] [bp+Ch]
  unsigned int varg_r2; // [sp+88h] [bp+10h]
  int varg_r3; // [sp+8Ch] [bp+14h]

  varg_r3 = a4;
  v61 = a4;
  LOBYTE(varg_r3) = a4;
  v62 = a3;
  varg_r2 = a3;
  v58 = a2;
  varg_r1 = a2;
  varg_r0 = a1;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v9 )
  {
    ProbeForWrite(a2, a3, 2);
    v59 = a6;
    v10 = a6;
    if ( (unsigned int)a6 >= MmUserProbeAddress )
      v10 = (_DWORD *)MmUserProbeAddress;
    *v10 = *v10;
    v60 = a7;
    if ( a7 )
    {
      v11 = a7;
      if ( (unsigned int)a7 >= MmUserProbeAddress )
        v11 = (unsigned int *)MmUserProbeAddress;
      *v11 = *v11;
    }
    if ( a5 )
    {
      v12 = 0;
      v63 = 0;
    }
    else
    {
      v12 = *a6;
      v63 = *a6;
    }
  }
  else if ( a5 )
  {
    v12 = 0;
    v60 = a7;
    v59 = a6;
  }
  else
  {
    v59 = a6;
    v12 = *a6;
    v60 = a7;
  }
  if ( a3 > a3 + 16 )
    return -1073741811;
  v14 = (_BYTE *)ExAllocatePoolWithQuotaTag(9u, a3 + 16, 1833853519);
  v15 = (unsigned int)v14;
  v64 = v14;
  v68 = v14;
  if ( !v14 )
    return -1073741670;
  memset(v14, 0, a3);
  v13 = ObReferenceObjectByHandle(a1, 1, ObpDirectoryObjectType, v9, &v56, 0);
  if ( v13 >= 0 )
  {
    v54 = v15;
    v55 = 16;
    v16 = 0;
    v52 = 0;
    v13 = -2147483622;
    v57 = -2147483622;
    v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v17 + 308);
    v18 = v56;
    v19 = v56 + 37;
    v69 = v56 + 37;
    v20 = KeAbPreAcquire((unsigned int)(v56 + 37), 0, 0);
    v21 = v20;
    do
      v22 = __ldrex(v19);
    while ( !v22 && __strex(0x11u, v19) );
    __dmb(0xBu);
    if ( v22 )
      ExfAcquirePushLockSharedEx(v18 + 37, v20, (unsigned int)(v18 + 37));
    if ( v21 )
      *(_BYTE *)(v21 + 14) |= 1u;
    ObfReferenceObject((int)v18);
    for ( i = 0; i < 0x25; ++i )
    {
      v25 = (_DWORD *)*v18++;
      for ( j = v25; j; j = (_DWORD *)*j )
      {
        if ( v12 == v16++ )
        {
          v27 = j[1] - 24;
          if ( (*(_BYTE *)(j[1] - 10) & 2) == 0
            || (v28 = ObpInfoMaskToOffset[*(_BYTE *)(j[1] - 10) & 3], v29 = v27 - v28, v27 == v28) )
          {
            RtlInitUnicodeString((unsigned int)&v65, 0);
            v30 = v66;
          }
          else
          {
            v65 = *(_DWORD *)(v29 + 4);
            v30 = *(_DWORD *)(v29 + 8);
            v66 = v30;
          }
          v51 = BYTE1(v27) ^ (unsigned __int8)ObHeaderCookie;
          v31 = v65;
          v32 = *(unsigned __int16 *)(ObTypeIndexTable[*(unsigned __int8 *)(v27 + 12) ^ v51] + 8)
              + (unsigned __int16)v65
              + 20;
          v67 = v32 + v55;
          if ( v32 + v55 > v62 )
          {
            if ( v61 )
            {
              v55 += v32;
              v13 = -1073741789;
            }
            else
            {
              v13 = 261;
            }
            v57 = v13;
            --v16;
            goto LABEL_45;
          }
          *(_WORD *)v54 = v65;
          *(_WORD *)(v54 + 2) = v31 + 2;
          *(_DWORD *)(v54 + 4) = v30;
          *(_WORD *)(v54 + 8) = *(_WORD *)(ObTypeIndexTable[*(unsigned __int8 *)(v27 + 12) ^ v51] + 8);
          *(_WORD *)(v54 + 10) = *(_WORD *)(ObTypeIndexTable[v51 ^ *(unsigned __int8 *)(v27 + 12)] + 8) + 2;
          *(_DWORD *)(v54 + 12) = *(_DWORD *)(ObTypeIndexTable[*(unsigned __int8 *)(v27 + 12) ^ v51] + 12);
          v13 = 0;
          v57 = 0;
          v55 = v67;
          v33 = (_DWORD *)(v54 + 16);
          v54 += 16;
          v34 = ++v52;
          if ( v61 )
            goto LABEL_46;
          ++v12;
        }
      }
    }
LABEL_45:
    v34 = v52;
    v33 = (_DWORD *)v54;
LABEL_46:
    v35 = (int)v64;
    v36 = v58;
    if ( v13 >= 0 )
    {
      *v33 = 0;
      v33[1] = 0;
      v33[2] = 0;
      v33[3] = 0;
      v37 = (int)(v33 + 4);
      v38 = (unsigned __int16 *)v35;
      if ( v34 )
      {
        do
        {
          v53 = v34 - 1;
          v39 = *v38;
          v38 += 8;
          memmove(v37, *((_DWORD *)v38 - 3), v39);
          *((_DWORD *)v38 - 3) = v37 - v35 + v36;
          v40 = (_WORD *)(v37 + *(v38 - 8));
          *v40++ = 0;
          memmove((int)v40, *((_DWORD *)v38 - 1), *(v38 - 4));
          *((_DWORD *)v38 - 1) = (char *)v40 + v36 - v35;
          v41 = (_WORD *)((char *)v40 + *(v38 - 4));
          *v41 = 0;
          v37 = (int)(v41 + 1);
          v34 = v53;
        }
        while ( v53 );
        v13 = v57;
      }
    }
    v42 = v69;
    __pld(v69);
    v43 = *v42;
    if ( (*v42 & 0xFFFFFFF0) <= 0x10 )
      v44 = 0;
    else
      v44 = v43 - 16;
    if ( (v43 & 2) != 0 )
      goto LABEL_58;
    __dmb(0xBu);
    do
      v45 = __ldrex(v42);
    while ( v45 == v43 && __strex(v44, v42) );
    if ( v45 != v43 )
LABEL_58:
      ExfReleasePushLock(v42, v43);
    KeAbPostRelease((unsigned int)v42);
    v46 = ObfDereferenceObject((int)v56);
    v47 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v48 = *(_WORD *)(v47 + 0x134) + 1;
    *(_WORD *)(v47 + 308) = v48;
    if ( !v48 && *(_DWORD *)(v47 + 100) != v47 + 100 && !*(_WORD *)(v47 + 310) )
      KiCheckForKernelApcDelivery(v46);
    v49 = v62;
    if ( v55 <= v62 )
      v49 = v55;
    memmove(v36, v35, v49);
    if ( v60 )
      *v60 = v55;
    if ( v13 >= 0 )
      *v59 = v16;
    ObfDereferenceObject((int)v56);
    ExFreePoolWithTag(v35);
  }
  else
  {
    ExFreePoolWithTag(v15);
  }
  return v13;
}
