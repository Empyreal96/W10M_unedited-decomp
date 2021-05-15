// PoStoreRequester 
 
int __fastcall PoStoreRequester(_DWORD *a1, char *a2, unsigned int *a3, int a4)
{
  int v6; // r1
  unsigned int v7; // r9
  int v8; // r6
  unsigned int v9; // r7
  char *v10; // r8
  BOOL v11; // r4
  int v12; // r10
  unsigned __int16 *v13; // r3
  unsigned int v14; // r6
  int v15; // r1
  _WORD *v16; // r2
  _WORD *v17; // r2
  int v18; // r0
  int v20; // r0
  int v21; // r6
  int v22; // r0
  int v23; // r2
  unsigned int v24; // r1
  int v25; // r3
  int v26; // r2
  int v27; // r3
  unsigned int v28; // [sp+8h] [bp-30h]
  int v29; // [sp+Ch] [bp-2Ch]
  int v30; // [sp+10h] [bp-28h]

  v6 = 0;
  v7 = *a3;
  v8 = 0;
  v9 = 24;
  v28 = 0;
  v29 = 0;
  v10 = 0;
  v30 = 0;
  v11 = a2 && v7 >= 0x18;
  if ( v11 )
  {
    v10 = a2 + 24;
    *((_DWORD *)a2 + 1) = *a1;
  }
  v12 = -1073741789;
  if ( !*a1 )
  {
    v18 = a1[1];
    if ( !v18 )
      goto LABEL_22;
    v20 = IoGetDeviceAttachmentBaseRef(v18);
    v21 = v20;
    if ( !v20 )
    {
LABEL_19:
      v6 = 0;
      v8 = 0;
      goto LABEL_22;
    }
    if ( *(_DWORD *)(*(_DWORD *)(v20 + 176) + 20) )
    {
      if ( v11 )
      {
        v22 = IoGetDeviceProperty(v20);
      }
      else
      {
        v22 = IoGetDeviceProperty(v20);
        if ( v22 == -1073741789 )
          v22 = 0;
      }
    }
    else
    {
      v22 = -1073741808;
    }
    if ( v22 < 0 )
    {
      v23 = *(_DWORD *)(v21 + 8);
      v24 = *(unsigned __int16 *)(v23 + 28) + 2;
      v28 = v24;
      v11 = v11 && v7 >= (unsigned int)*(unsigned __int16 *)(v23 + 28) + 26;
      if ( !v11 )
        goto LABEL_38;
      RtlStringCbCopyUnicodeString(v10, v24, v23 + 28);
    }
    v24 = v28;
LABEL_38:
    v9 = v24 + 24;
    if ( v11 )
    {
      v30 = 1;
      *((_DWORD *)a2 + 2) = v10 - a2;
      v10 += v24;
    }
    v25 = *(_DWORD *)(*(_DWORD *)(v21 + 176) + 20);
    if ( v25 )
    {
      v26 = v25 + 20;
      v27 = *(unsigned __int16 *)(v25 + 20);
      v29 = v26;
      v9 += v27 + 2;
      v11 = v11 && v7 >= v9;
      if ( v11 )
      {
        RtlStringCbCopyUnicodeString(v10, v27 + 2, v26);
        *((_DWORD *)a2 + 3) = v10 - a2;
      }
    }
    ObfDereferenceObjectWithTag(v21);
    v6 = v29;
    v8 = v30;
    goto LABEL_22;
  }
  if ( v11 )
  {
    *((_DWORD *)a2 + 3) = *(_DWORD *)(a1[1] + 176);
    *((_DWORD *)a2 + 4) = a1[2];
  }
  v13 = *(unsigned __int16 **)(a1[1] + 380);
  v14 = *v13;
  v15 = *((_DWORD *)v13 + 1);
  if ( a4 )
  {
    v16 = (_WORD *)(v15 + 2 * (v14 >> 1));
    if ( v16 != (_WORD *)v15 )
    {
      do
      {
        if ( *v16 == 92 )
          break;
        --v16;
      }
      while ( v16 != (_WORD *)v15 );
      if ( v16 != (_WORD *)v15 )
      {
        v17 = v16 + 1;
        v14 += v15 - (_DWORD)v17;
        v15 = (int)v17;
      }
    }
  }
  v9 = v14 + 26;
  v11 = v11 && v7 >= v9;
  if ( !v11 )
    goto LABEL_19;
  memmove((int)v10, v15, v14);
  *(_WORD *)&v10[2 * (v14 >> 1)] = 0;
  v6 = 0;
  *((_DWORD *)a2 + 2) = v10 - a2;
  v8 = 0;
LABEL_22:
  *a3 = v9;
  if ( v11 )
  {
    if ( !*((_DWORD *)a2 + 1) )
    {
      if ( !v8 )
        *((_DWORD *)a2 + 2) = 0;
      if ( !v6 )
        *((_DWORD *)a2 + 3) = 0;
    }
    v12 = 0;
  }
  return v12;
}
