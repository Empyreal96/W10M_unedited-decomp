// ObpCheckObjectReference 
 
int __fastcall ObpCheckObjectReference(int a1, int *a2, int a3, char a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21)
{
  int v21; // r7
  int v24; // r4
  int v25; // r0
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r4
  int v30; // r0
  int v31; // r6
  int v32; // r2
  __int64 v33; // kr00_8
  int v35; // lr
  __int16 v36; // r3
  int v37; // r2
  int v38; // r1
  int v39; // r3
  int v40; // r0
  int v41; // r2
  int v42; // r3
  int v43; // r1
  int v44; // [sp+8h] [bp-40h]
  char v45; // [sp+18h] [bp-30h] BYREF
  char v46; // [sp+19h] [bp-2Fh] BYREF
  char v47[2]; // [sp+1Ah] [bp-2Eh] BYREF
  int v48; // [sp+1Ch] [bp-2Ch] BYREF
  int v49; // [sp+20h] [bp-28h] BYREF
  int v50[9]; // [sp+24h] [bp-24h] BYREF

  v21 = a4;
  v48 = 0;
  v49 = 0;
  v24 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(a1 - 12)];
  v25 = ObpGetObjectSecurity(a1, v50, v47, a4);
  if ( v25 >= 0 )
  {
    SeLockSubjectContext(a2 + 7);
    v44 = v24 + 52;
    v29 = v50[0];
    v30 = SeAccessCheck(v50[0], (int)(a2 + 7), 1, a2[4], a2[5], (int)&v49, v44, v21, (int)&v48, a5);
    v31 = v30;
    if ( v30 )
    {
      v32 = v48;
      a2[5] |= v48;
      a2[4] &= ~v32;
    }
    if ( !v29 )
      goto LABEL_6;
    v33 = *((_QWORD *)a2 + 2);
    v45 = 0;
    v46 = 0;
    if ( !v21 || !SepAdtAuditThisEventWithContext(120, v30, 0, a2 + 7) )
      goto LABEL_6;
    v35 = a2[7];
    if ( !v35 )
      v35 = a2[9];
    v36 = *(_WORD *)(v29 + 2);
    if ( (v36 & 0x10) == 0 )
      goto LABEL_16;
    if ( (*(_WORD *)(v29 + 2) & 0x8000) == 0 )
    {
      v38 = *(_DWORD *)(v29 + 12);
      goto LABEL_18;
    }
    v37 = *(_DWORD *)(v29 + 12);
    if ( v37 )
      v38 = v37 + v29;
    else
LABEL_16:
      v38 = 0;
    if ( (v36 & 0x10) == 0 )
      goto LABEL_22;
LABEL_18:
    if ( (*(_WORD *)(v29 + 2) & 0x8000) == 0 )
    {
      v40 = *(_DWORD *)(v29 + 12);
      goto LABEL_24;
    }
    v39 = *(_DWORD *)(v29 + 12);
    if ( v39 )
      v40 = v39 + v29;
    else
LABEL_22:
      v40 = 0;
LABEL_24:
    SeExamineSacl(v40, v38, v35, HIDWORD(v33) | v33, v31, &v45, &v46);
    v41 = a2[7];
    if ( !v41 )
      v41 = a2[9];
    if ( (*(_WORD *)(v29 + 2) & 0x10) == 0 )
      goto LABEL_30;
    if ( (*(_WORD *)(v29 + 2) & 0x8000) == 0 )
    {
      v43 = *(_DWORD *)(v29 + 12);
      goto LABEL_32;
    }
    v42 = *(_DWORD *)(v29 + 12);
    if ( v42 )
      v43 = v42 + v29;
    else
LABEL_30:
      v43 = 0;
LABEL_32:
    SeExamineGlobalSacl(
      ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie]
    + 8,
      v43,
      v41,
      HIDWORD(v33) | v33,
      v31,
      &v45,
      &v46);
    if ( v45 || v46 )
      SepAdtObjectReferenceAuditAlarm(a1, a2 + 7, HIDWORD(v33) | v33, v31);
LABEL_6:
    SeUnlockSubjectContext(a2 + 7);
    ObReleaseObjectSecurity(v29, (unsigned __int8)v47[0]);
    return v31;
  }
  return sub_7C4A14(v25, v26, v27, v28, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21);
}
