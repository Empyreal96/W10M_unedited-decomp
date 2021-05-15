// NtGetNlsSectionPtr 
 
int __fastcall NtGetNlsSectionPtr(int a1, int a2, unsigned int a3, _DWORD *a4, _DWORD *a5)
{
  int v7; // r4
  int v8; // r6
  _DWORD *v9; // r2
  _DWORD *v10; // r2
  int v11; // r5
  int v12; // r0
  int v13; // r1
  int v15; // [sp+1Ch] [bp-194h] BYREF
  int v16; // [sp+20h] [bp-190h]
  _DWORD v17[3]; // [sp+24h] [bp-18Ch] BYREF
  _DWORD v18[2]; // [sp+30h] [bp-180h] BYREF
  _DWORD v19[2]; // [sp+38h] [bp-178h] BYREF
  _DWORD *v20; // [sp+40h] [bp-170h]
  _DWORD *v21; // [sp+44h] [bp-16Ch]
  _DWORD *v22; // [sp+48h] [bp-168h]
  int v23; // [sp+50h] [bp-160h]
  int v24; // [sp+54h] [bp-15Ch]
  int *v25; // [sp+58h] [bp-158h]
  int v26; // [sp+5Ch] [bp-154h]
  int v27; // [sp+60h] [bp-150h]
  int v28; // [sp+64h] [bp-14Ch]
  int v29; // [sp+68h] [bp-148h]
  int v30; // [sp+6Ch] [bp-144h]
  _DWORD *v31; // [sp+70h] [bp-140h]
  int v32; // [sp+74h] [bp-13Ch]
  int v33; // [sp+78h] [bp-138h]
  int v34; // [sp+7Ch] [bp-134h]
  int v35; // [sp+80h] [bp-130h] BYREF
  int v36; // [sp+90h] [bp-120h] BYREF
  _DWORD _110[46]; // [sp+110h] [bp-A0h] BYREF

  _110[44] = a3;
  _110[45] = a4;
  v21 = a4;
  v15 = a2;
  _110[43] = a2;
  _110[42] = a1;
  v22 = a4;
  v20 = a5;
  v19[0] = a5;
  v17[2] = 0;
  v16 = 0;
  v17[0] = 0;
  v18[0] = 0;
  if ( !a4 )
    return -1073741582;
  if ( !a5 )
    return -1073741581;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v8 )
  {
    v9 = a4;
    if ( (unsigned int)a4 >= MmUserProbeAddress )
      v9 = (_DWORD *)MmUserProbeAddress;
    *v9 = *v9;
    v10 = a5;
    if ( (unsigned int)a5 >= MmUserProbeAddress )
      v10 = (_DWORD *)MmUserProbeAddress;
    *v10 = *v10;
    if ( a3 )
    {
      if ( (a3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      if ( a3 + 4 > MmUserProbeAddress || a3 + 4 < a3 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  v7 = RtlpInitNlsSectionName(a1, v15, &v36);
  if ( v7 >= 0 )
  {
    v23 = 24;
    v24 = 0;
    v26 = 720;
    v25 = &v35;
    v27 = 0;
    v28 = 0;
    if ( a1 == 11 || a1 == 12 )
    {
      v7 = ZwOpenSection();
      if ( v7 < 0 )
      {
        v7 = RtlpInitNlsFileName(a1, v15, _110);
        if ( v7 < 0 )
          return v7;
        v29 = 24;
        v30 = 0;
        v32 = 576;
        v31 = v19;
        v33 = 0;
        v34 = 0;
        v7 = ZwOpenFile();
        if ( v7 < 0 )
          return v7;
        v7 = ZwCreateSection();
        ZwClose();
      }
    }
    else
    {
      v7 = -1073741823;
    }
    if ( v7 >= 0 )
    {
      v7 = ObReferenceObjectByHandle(v16, 983071, MmSectionObjectType, 0, &v15);
      ZwClose();
      if ( v7 >= 0 )
      {
        v19[0] = 0;
        v19[1] = 0;
        if ( v8 )
        {
          v13 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
          v11 = v15;
          v12 = MmMapViewOfSection(v15, v13, v17, 0, 0, v19, v18, 1, 0x400000, 2);
        }
        else
        {
          v11 = v15;
          v12 = MmMapViewInSystemSpace(v15, (int)v17, (int)v18);
        }
        v7 = v12;
        ObfDereferenceObject(v11);
        if ( v7 >= 0 )
        {
          *v21 = v17[0];
          *v20 = v18[0];
        }
      }
    }
  }
  return v7;
}
