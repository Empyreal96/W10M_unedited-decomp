// PspCreateProcess 
 
int __fastcall PspCreateProcess(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned int *a8)
{
  int v9; // r4
  int v10; // r9
  int v11; // r4
  _BYTE *v12; // r0
  int v13; // r2
  int v14; // r3
  int v15; // r8
  int v16; // r5
  char v17; // r3
  int v18; // r1
  char v19; // r0
  int v20; // r0
  int v21; // r9
  char v22; // r1
  unsigned int *v23; // r6
  unsigned __int8 v25; // [sp+28h] [bp-1A0h] BYREF
  char v26; // [sp+29h] [bp-19Fh] BYREF
  char v27[2]; // [sp+2Ah] [bp-19Eh] BYREF
  int v28; // [sp+2Ch] [bp-19Ch] BYREF
  char v29; // [sp+30h] [bp-198h]
  int v30; // [sp+34h] [bp-194h] BYREF
  unsigned int *v31; // [sp+38h] [bp-190h] BYREF
  unsigned int *v32; // [sp+3Ch] [bp-18Ch] BYREF
  unsigned int *v33; // [sp+40h] [bp-188h]
  int v34; // [sp+44h] [bp-184h]
  int v35; // [sp+48h] [bp-180h]
  int v36; // [sp+50h] [bp-178h]
  _DWORD *v37; // [sp+54h] [bp-174h]
  int v38; // [sp+58h] [bp-170h]
  int v39; // [sp+5Ch] [bp-16Ch]
  _DWORD _60[96]; // [sp+60h] [bp-168h] BYREF

  _60[92] = a1;
  _60[94] = a3;
  _60[95] = a4;
  v30 = a4;
  v35 = a2;
  _60[93] = a2;
  v37 = a1;
  v33 = a1;
  v28 = a3;
  v39 = a4;
  v38 = a6;
  v36 = a7;
  v34 = a7;
  v31 = a8;
  v32 = a8;
  v9 = __mrc(15, 0, 13, 0, 3);
  v10 = *(char *)((v9 & 0xFFFFFFC0) + 0x15A);
  v29 = *(_BYTE *)((v9 & 0xFFFFFFC0) + 0x15A);
  if ( (a5 & 0xFFFF6840) != 0 || (*(_BYTE *)(*(_DWORD *)((v9 & 0xFFFFFFC0) + 0x74) + 734) & 7) != 0 && v10 )
    return -1073741811;
  v12 = memset(_60, 0, 324);
  LOBYTE(_60[79]) = v10;
  if ( a3 )
  {
    if ( v10 )
    {
      if ( (a3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v12);
      v13 = *(_DWORD *)(a3 + 12);
      _60[78] = v13;
    }
    else
    {
      v13 = *(_DWORD *)(a3 + 12);
    }
    if ( v10 )
      v14 = 3570;
    else
      v14 = 69618;
    _60[78] = v14 & v13;
  }
  if ( a6 )
  {
    v11 = ObReferenceObjectByHandle(a6, 8, MmSectionObjectType, v10, (int)&v32, 0);
    v15 = (int)v32;
    v33 = v32;
    if ( v11 < 0 )
      return v11;
  }
  else
  {
    v15 = 0;
    v33 = 0;
  }
  if ( !v30 )
  {
    v16 = 0;
    v30 = 0;
LABEL_23:
    v11 = PspReferenceTokenForNewProcess(v16, (int)v31, v10, &v28);
    if ( v11 < 0 )
      goto LABEL_45;
    if ( v16 )
    {
      if ( v15 )
      {
        v25 = 0;
        v11 = SeQuerySigningPolicy(v28, 0, 0, 0, &v26, v27, &v25);
        if ( v11 < 0 )
        {
LABEL_44:
          ObfDereferenceObject(v28);
LABEL_45:
          if ( v16 )
            ObfDereferenceObjectWithTag(v16);
          goto LABEL_47;
        }
        v17 = v26;
        if ( v26 && v26 != 1 || (v18 = v25) != 0 )
        {
          v11 = -1073741637;
          goto LABEL_44;
        }
        v19 = v27[0];
LABEL_35:
        v20 = PspAllocateProcess((_DWORD *)v16, v10, a3, v18, v17, v19, v15, v28, a5, 0, v31 != 0, &v32, &v31);
        v11 = v20;
        if ( v20 >= 0 )
        {
          v21 = v20;
          v34 = v20;
          v22 = 1;
          if ( v32 )
            v22 = 3;
          v23 = v31;
          v11 = PspInsertProcess(v31, v16, v35, a5, v36, v22, 0);
          if ( v11 < 0 )
            goto LABEL_42;
          v11 = PspCreateObjectHandle((int)v23, (int)_60, PsProcessType);
          if ( v11 >= 0 )
          {
            *v37 = _60[80];
            v11 = v21;
          }
          SepDeleteAccessState((int)_60);
          SeReleaseSubjectContext((int)&_60[7]);
          if ( v11 < 0 )
LABEL_42:
            PspRundownSingleProcess(v23, 0);
          ObfDereferenceObjectWithTag((int)v23);
        }
        goto LABEL_44;
      }
      v18 = *(unsigned __int8 *)(v16 + 734);
      v25 = *(_BYTE *)(v16 + 734);
      v19 = *(_BYTE *)(v16 + 733);
      v27[0] = v19;
      v17 = *(_BYTE *)(v16 + 732);
    }
    else
    {
      v18 = 98;
      v25 = 98;
      v17 = 30;
      v19 = 28;
      v27[0] = 28;
    }
    v26 = v17;
    goto LABEL_35;
  }
  v11 = ObReferenceObjectByHandleWithTag(v30, 128, PsProcessType, v10, 1917023056, &v30, 0);
  if ( v11 >= 0 )
  {
    v16 = v30;
    goto LABEL_23;
  }
LABEL_47:
  if ( v15 )
    ObfDereferenceObject(v15);
  return v11;
}
