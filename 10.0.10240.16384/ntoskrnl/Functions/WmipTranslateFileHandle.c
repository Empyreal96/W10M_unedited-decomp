// WmipTranslateFileHandle 
 
int __fastcall WmipTranslateFileHandle(int a1, unsigned int *a2)
{
  int v3; // r0
  int v5; // r4
  int v6; // r6
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r10
  unsigned int v10; // r8
  int v11; // r1
  unsigned int v12; // r2
  _WORD *v13; // r3
  int v15; // [sp+8h] [bp-30h] BYREF
  int v16; // [sp+Ch] [bp-2Ch] BYREF
  int v17; // [sp+10h] [bp-28h] BYREF
  int v18; // [sp+14h] [bp-24h]

  v3 = *(_DWORD *)a1;
  v18 = 0;
  v5 = WmipGetFilePDO(v3, 1, &v15, 0);
  if ( v5 < 0 )
    return v5;
  v5 = ObReferenceObjectByHandle(*(_DWORD *)(a1 + 8), 1, WmipGuidObjectType, 1, (int)&v16, 0);
  v6 = v15;
  if ( v5 >= 0 )
  {
    v7 = v16;
    v5 = WmipGetGuidObjectInstanceInfo(v16, v15, &v17, &v15);
    if ( v5 < 0 )
    {
LABEL_12:
      if ( v7 )
        ObfDereferenceObject(v7);
      goto LABEL_14;
    }
    v8 = (unsigned __int16)v17;
    v9 = v18;
    v10 = (unsigned __int16)v17 + 26;
    if ( *a2 >= v10 )
    {
      v11 = v18;
      *(_DWORD *)(a1 + 16) = v15;
      *(_WORD *)(a1 + 20) = v8 + 4;
      memmove(a1 + 22, v11, v8);
      v12 = (unsigned __int16)v17;
      *a2 = v10;
      v13 = (_WORD *)(a1 + 22 + 2 * (unsigned __int16)(v12 >> 1));
      *v13 = 0;
      v13[1] = 0;
    }
    else
    {
      if ( *a2 < 4 )
      {
        v5 = -1073741823;
        goto LABEL_10;
      }
      *a2 = 4;
      *(_DWORD *)a1 = v10;
    }
    v5 = 0;
LABEL_10:
    if ( v9 )
      RtlFreeAnsiString(&v17);
    goto LABEL_12;
  }
LABEL_14:
  if ( v6 )
    ObfDereferenceObject(v6);
  return v5;
}
