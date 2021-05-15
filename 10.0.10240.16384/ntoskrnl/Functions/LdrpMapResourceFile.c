// LdrpMapResourceFile 
 
int __fastcall LdrpMapResourceFile(int a1, int a2, _DWORD *a3, int *a4, int *a5)
{
  int v6; // r5
  int v7; // r6
  int v12; // r4
  int v13; // r7
  int v14; // r0
  int v15; // [sp+24h] [bp-5Ch] BYREF
  int v16; // [sp+28h] [bp-58h]
  int v17; // [sp+2Ch] [bp-54h] BYREF
  int v18[4]; // [sp+30h] [bp-50h] BYREF
  int v19; // [sp+48h] [bp-38h]
  int v20; // [sp+4Ch] [bp-34h]
  int v21; // [sp+50h] [bp-30h]
  int v22; // [sp+54h] [bp-2Ch]
  int v23; // [sp+58h] [bp-28h]
  int v24; // [sp+5Ch] [bp-24h]

  v6 = 0;
  v7 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  if ( !a1 || !a2 || !a4 )
    return -1073741811;
  if ( !RtlImageNtHeader(a1 & 0xFFFFFFFC) )
    return sub_54DCF8();
  v19 = 24;
  v20 = 0;
  v21 = a2;
  v23 = 0;
  v24 = 0;
  v22 = 576;
  v12 = ZwCreateFile();
  if ( v12 >= 0 )
  {
    v19 = 24;
    v20 = 0;
    v21 = 0;
    v23 = 0;
    v24 = 0;
    v18[2] = 0;
    v18[3] = 0;
    v22 = 576;
    v12 = ZwCreateSection();
    if ( v12 >= 0 )
    {
      v12 = ObReferenceObjectByHandle(v16, 0, 0, 0, v18, 0);
      ZwClose();
      v13 = v18[0];
      if ( v12 >= 0 )
      {
        v12 = MmMapViewInSystemSpace(v18[0], &v17, &v15);
        v6 = v17;
        if ( v12 < 0 )
        {
          v7 = v15;
        }
        else
        {
          v14 = RtlImageNtHeader(v17);
          v7 = v15;
          if ( !v14 )
            v12 = -1073741701;
        }
      }
      if ( v13 )
        ObfDereferenceObjectWithTag(v13);
      if ( v12 < 0 )
      {
        if ( v6 )
          MmUnmapViewInSystemSpace(v6);
      }
      else
      {
        *a4 = v6;
        if ( a5 )
          *a5 = v7;
        if ( a3 )
          *a3 = 0;
      }
    }
  }
  return v12;
}
