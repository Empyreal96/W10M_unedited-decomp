// AdtpBuildAccessReasonAuditString 
 
int __fastcall AdtpBuildAccessReasonAuditString(int a1, int a2, _DWORD *a3, int a4, int a5, int *a6, int a7, unsigned int *a8, _BYTE *a9)
{
  int v10; // r3
  int v11; // r5
  int v12; // r4
  int v13; // r2
  int v14; // r9
  int v15; // r10
  int v16; // r8
  _DWORD *v17; // r0
  int v18; // t1
  int v19; // r3
  int v20; // r0
  int *v21; // r5
  int v22; // r0
  unsigned int v23; // r8
  unsigned __int16 *v24; // r4
  int v25; // r1
  int v26; // r0
  unsigned int v27; // r1
  int v28; // r5
  unsigned __int16 *v29; // r4
  unsigned int v30; // r10
  _DWORD *v31; // r8
  int v32; // r0
  int v33; // r8
  unsigned int v34; // r2
  int v35; // r5
  int v36; // r10
  int v37; // r3
  unsigned __int16 *v38; // r7
  int v39; // r1
  unsigned int v40; // r4
  _QWORD *v41; // r4
  int v42; // r0
  int v44; // [sp+4h] [bp-184h]
  int v45; // [sp+24h] [bp-164h]
  unsigned int v46; // [sp+28h] [bp-160h]
  int v47; // [sp+2Ch] [bp-15Ch]
  int v50; // [sp+38h] [bp-150h]
  int v51; // [sp+40h] [bp-148h] BYREF
  int v52; // [sp+44h] [bp-144h]
  int v53; // [sp+48h] [bp-140h]
  int v54; // [sp+50h] [bp-138h] BYREF
  int v55; // [sp+54h] [bp-134h]
  int v56; // [sp+58h] [bp-130h]
  int v57; // [sp+5Ch] [bp-12Ch]
  unsigned int *v58; // [sp+60h] [bp-128h]
  _BYTE v59[288]; // [sp+68h] [bp-120h] BYREF

  v57 = a7;
  v58 = a8;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v10 = *a3;
  v11 = 0;
  v45 = 0;
  v46 = 0;
  v12 = 0;
  v13 = 1;
  v50 = a2;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v51 = 0;
  if ( !v10 )
  {
LABEL_2:
    if ( a6 )
      AdtpEtwBuildDashString(a6, a2);
    return v11;
  }
  v17 = a3;
  a2 = 32;
  do
  {
    v18 = v17[1];
    ++v17;
    v19 = v18 & 0xFF0000;
    if ( (v18 & 0xFF0000) == 0 )
      goto LABEL_15;
    if ( v19 == 0x10000 || v19 == 0x20000 )
      goto LABEL_14;
    if ( v19 == 196608 || v19 == 0x40000 )
      goto LABEL_13;
    if ( v19 != 327680 )
    {
      if ( v19 != 393216 )
      {
        v13 = 0;
        goto LABEL_15;
      }
LABEL_13:
      v15 = 1;
    }
LABEL_14:
    v13 = 0;
    v12 = 1;
LABEL_15:
    --a2;
  }
  while ( a2 );
  if ( v13 == 1 )
    goto LABEL_2;
  memset(v59, 0, 256);
  if ( v12 == 1 )
  {
    AdtpBuildContextFromSecurityDescriptor(a3 + 35, &v51);
    v16 = v51;
  }
  if ( v15 == 1 )
  {
    v20 = RtlLengthSecurityDescriptor(v16);
    AdtpBuildContextFromSecurityDescriptor(v20 + v16, &v54);
  }
  v21 = &AdtpStandardAccessTypes;
  v22 = a4;
  v23 = 0;
  v24 = (unsigned __int16 *)v59;
  while ( 2 )
  {
    if ( v22 == 1 )
    {
      if ( (int)a3[AdtpPermissionBitPosition(*v21) + 1] < 0 )
      {
        v26 = AdtpBuildStagingReasonAuditStringInternal(a1, v50, &v51, &v54, v25, v44, a3 + 1, v24);
        goto LABEL_27;
      }
      v27 = v46;
LABEL_31:
      v22 = a4;
    }
    else
    {
      if ( (*v21 & *a3) != 0 )
      {
        v26 = AdtpBuildAccessReasonAuditStringInternal(a1, v50, &v51, &v54, *v21 & *a3, v44, a3 + 1, v24);
LABEL_27:
        v45 = v26;
        if ( v26 < 0 )
          goto LABEL_58;
        ++v14;
        v27 = v46 + *v24;
        v46 = v27;
        v24 += 4;
        goto LABEL_31;
      }
      v27 = v46;
    }
    ++v23;
    ++v21;
    if ( v23 < 7 )
      continue;
    break;
  }
  if ( *(_WORD *)a3 )
  {
    v28 = 1;
    v29 = (unsigned __int16 *)&v59[8 * v14];
    v30 = 0;
    v31 = a3;
    do
    {
      if ( v22 == 1 )
      {
        if ( (v31[1] & 0x80000000) != 0 )
        {
          v32 = AdtpBuildStagingReasonAuditStringInternal(a1, v50, &v51, &v54, v28, v44, a3 + 1, v29);
LABEL_40:
          v45 = v32;
          if ( v32 < 0 )
            goto LABEL_58;
          v22 = a4;
          ++v14;
          v27 = v46 + *v29;
          v46 = v27;
          v29 += 4;
          goto LABEL_42;
        }
      }
      else if ( (*a3 & v28) != 0 )
      {
        v32 = AdtpBuildAccessReasonAuditStringInternal(a1, v50, &v51, &v54, *a3 & v28, v44, a3 + 1, v29);
        goto LABEL_40;
      }
LABEL_42:
      ++v30;
      v28 *= 2;
      ++v31;
    }
    while ( v30 < 0x10 );
  }
  v33 = (v27 >> 1) + 1;
  if ( v57 && v58 && (v34 = *v58 + v33, v34 < 0x400) )
  {
    v35 = v57 + 2 * *v58;
    *v58 = v34;
    *a9 = 0;
LABEL_50:
    v36 = 0;
    if ( v14 )
    {
      v37 = v14;
      v47 = v14;
      v38 = (unsigned __int16 *)v59;
      do
      {
        v39 = *((_DWORD *)v38 + 1);
        if ( v39 )
        {
          v40 = *v38;
          memmove(v36 + v35, v39, v40);
          v37 = v47;
          v36 += v40;
        }
        v38 += 4;
        v47 = --v37;
      }
      while ( v37 );
    }
    *(_WORD *)(2 * v33 + v35 - 2) = 0;
    if ( a6 )
    {
      *a6 = v35;
      a6[1] = 0;
      a6[2] = 2 * v33;
      a6[3] = 0;
    }
    else
    {
      MEMORY[0] = 2 * (v33 - 1);
      MEMORY[2] = 2 * (v33 - 1) + 2;
      MEMORY[4] = v35;
    }
LABEL_58:
    v11 = v45;
  }
  else
  {
    v35 = ExAllocatePoolWithTag(1, 2 * v33);
    if ( v35 )
    {
      *a9 = 1;
      goto LABEL_50;
    }
    v11 = -1073741801;
  }
  if ( v14 )
  {
    v41 = v59;
    do
    {
      v42 = *((_DWORD *)v41 + 1);
      if ( v42 )
        ExFreePoolWithTag(v42);
      ++v41;
      --v14;
    }
    while ( v14 );
  }
  if ( v52 && v53 )
    ExFreePoolWithTag(v53);
  if ( v55 && v56 )
    ExFreePoolWithTag(v56);
  return v11;
}
