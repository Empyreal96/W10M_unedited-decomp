// sub_816360 
 
int __fastcall sub_816360(int a1, int a2, char a3, int a4, int a5, int a6)
{
  int v6; // r4
  unsigned int v7; // r0
  _DWORD *v8; // r6
  int v9; // r0
  _DWORD *v11; // r5
  int v12; // r7
  unsigned int *v13; // r8
  _DWORD *v14; // r9
  int v15; // r10
  char *v16; // r6
  unsigned int v17; // r8
  int i; // r2
  int v19; // r1
  int v20; // r0
  char *v21; // r5
  _DWORD *v22; // t1
  char v23; // [sp+8h] [bp-88h] BYREF
  char v24[3]; // [sp+9h] [bp-87h] BYREF
  unsigned int v25; // [sp+Ch] [bp-84h] BYREF
  char *v26; // [sp+10h] [bp-80h] BYREF
  int v27; // [sp+14h] [bp-7Ch]
  unsigned int *v28; // [sp+18h] [bp-78h]
  _DWORD v29[2]; // [sp+20h] [bp-70h] BYREF
  char v30[100]; // [sp+28h] [bp-68h] BYREF
  int (__fastcall *v31)(int); // [sp+8Ch] [bp-4h]

  v6 = ObReferenceObjectByPointer(v15, DesiredAccessForFunction[v12], WmipGuidObjectType, a3);
  if ( v6 < 0 )
    return v31(v6);
  v26 = v30;
  v25 = 16;
  v6 = WmipPrepareWnodeSI(v15, v11, (int *)&v25, (int *)&v26, &v23, v24);
  if ( v6 >= 0 )
  {
    v7 = a6;
    if ( v24[0] )
    {
      v11[11] |= 0x100u;
      *v11 = 48;
      v14[7] = 48;
      goto LABEL_10;
    }
    if ( v23 )
    {
      if ( v12 == 3 || v12 == 9 )
        v6 = -1073741161;
      else
        v6 = -1073741162;
      v17 = v25;
      v16 = v26;
      v27 = 0;
      if ( v25 )
      {
        for ( i = (int)v26; ; i = (int)v26 )
        {
          v19 = *(_DWORD *)(*(_DWORD *)i + 44);
          v26 = (char *)(i + 4);
          v11[1] = v19;
          if ( v14 )
          {
            v25 = (unsigned int)(v14 + 6);
            v20 = WmipForwardWmiIrp(v14, v12, v19, (int)(v11 + 6), v7, (int)v11);
          }
          else
          {
            v25 = (unsigned int)v29;
            v20 = WmipSendWmiIrp(v12, v19, (int)(v11 + 6), v7, (int)v11, v29);
          }
          if ( v20 >= 0 )
            *v28 = *(_DWORD *)(v25 + 4);
          if ( v20 != -1073741162 && v20 != -1073741163 )
            break;
          if ( ++v27 >= v17 )
            goto LABEL_31;
          v7 = a6;
        }
        v6 = v20;
LABEL_31:
        if ( v17 )
        {
          v21 = v16;
          do
          {
            v22 = *(_DWORD **)v21;
            v21 += 4;
            WmipUnreferenceEntry((int *)&WmipISChunkInfo, v22);
            --v17;
          }
          while ( v17 );
        }
      }
      if ( v16 != v30 && v16 )
        ExFreePoolWithTag((unsigned int)v16);
      v13 = v28;
      goto LABEL_9;
    }
    if ( v14 )
    {
      v8 = v14 + 6;
      v9 = WmipForwardWmiIrp(v14, v12, v11[1], (int)(v11 + 6), a6, (int)v11);
    }
    else
    {
      v8 = v29;
      v9 = WmipSendWmiIrp(v12, v11[1], (int)(v11 + 6), a6, (int)v11, v29);
    }
    v6 = v9;
    if ( v9 >= 0 )
    {
      *v13 = v8[1];
LABEL_9:
      v7 = a6;
LABEL_10:
      if ( v6 >= 0 && *v13 > v7 )
        v6 = -1073741811;
      goto LABEL_13;
    }
  }
LABEL_13:
  if ( v15 )
    ObfDereferenceObject(v15);
  return v31(v6);
}
