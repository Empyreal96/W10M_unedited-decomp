// WmipCreateGuidObject 
 
int __fastcall WmipCreateGuidObject(_DWORD *a1, int a2, int a3, _DWORD *a4)
{
  int v4; // r4
  int v8; // r4
  int v9; // r5
  int v10; // r3
  _BYTE *v11; // r6
  int v12; // r10
  int v13; // r8
  _DWORD *v14; // r5
  _DWORD *v15; // lr
  int v16; // r1
  int v17; // r2
  int v18; // r3
  _BYTE *v20; // [sp+18h] [bp-190h] BYREF
  int v21; // [sp+1Ch] [bp-18Ch]
  int v22[2]; // [sp+20h] [bp-188h] BYREF
  _DWORD *v23; // [sp+28h] [bp-180h]
  int v24; // [sp+2Ch] [bp-17Ch]
  _DWORD v25[6]; // [sp+30h] [bp-178h] BYREF
  char v26[28]; // [sp+48h] [bp-160h] BYREF
  int v27; // [sp+64h] [bp-144h] BYREF
  int v28; // [sp+68h] [bp-140h]
  int v29; // [sp+6Ch] [bp-13Ch]
  int v30; // [sp+70h] [bp-138h]
  char v31[232]; // [sp+C0h] [bp-E8h] BYREF

  v4 = a1[2];
  v23 = (_DWORD *)a3;
  v24 = a2;
  RtlInitUnicodeString((unsigned int)v22, (unsigned __int16 *)(*(_DWORD *)(v4 + 4) + 18));
  v8 = WmipGetGuidSecurityDescriptor(v22, &v20);
  if ( v8 >= 0 )
  {
    v9 = a1[1];
    v10 = a1[5];
    v25[0] = *a1;
    v25[1] = v9;
    v25[5] = v10;
    v11 = v20;
    v25[3] = 640;
    v25[4] = v20;
    v25[2] = 0;
    v8 = SeCreateAccessState((int)v26, (int)v31, a2, WmipGenericMapping);
    if ( v8 >= 0 )
    {
      v12 = v28;
      v13 = v27;
      v21 = v29;
      v22[0] = v30;
      v27 = WmipSystemSubjectContext;
      v28 = unk_922BF4;
      v29 = unk_922BF8;
      v30 = unk_922BFC;
      v8 = ObCreateObject(0, (_DWORD *)WmipGuidObjectType, (int)v25, 0, 0, 108, 0, 0, &v20);
      if ( v8 >= 0 )
      {
        v14 = v20;
        memset(v20, 0, 108);
        KeInitializeEvent((int)v14, 0, 0);
        v15 = v23;
        v14[17] = 4096;
        v14[22] = 4096;
        v16 = v15[1];
        v17 = v15[2];
        v18 = v15[3];
        v14[4] = *v15;
        v14[5] = v16;
        v14[6] = v17;
        v14[7] = v18;
        v8 = ObInsertObject((int)v14, (int)v26, v24, 0, 0, 0);
        if ( v8 >= 0 )
        {
          *a4 = v14;
          v8 = 0;
        }
      }
      v27 = v13;
      v28 = v12;
      v29 = v21;
      v30 = v22[0];
      SepDeleteAccessState((int)v26);
      SeReleaseSubjectContext((int)&v27);
    }
    if ( v11 && v11 != (_BYTE *)WmipDefaultAccessSd )
      ExFreePoolWithTag((unsigned int)v11);
  }
  return v8;
}
