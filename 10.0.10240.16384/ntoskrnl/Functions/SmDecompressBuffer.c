// SmDecompressBuffer 
 
int __fastcall SmDecompressBuffer(int *a1, unsigned int a2, int *a3, unsigned int *a4, unsigned int *a5, int a6)
{
  int v6; // r9
  int v7; // r8
  unsigned int v8; // r7
  unsigned int v10; // r5
  int v11; // r0
  int v12; // r6
  int v13; // r3
  int v14; // r4
  unsigned int v15; // [sp+10h] [bp-38h] BYREF
  int *v16; // [sp+14h] [bp-34h]
  int v17; // [sp+18h] [bp-30h] BYREF
  int *v18; // [sp+1Ch] [bp-2Ch]
  unsigned int *v19; // [sp+20h] [bp-28h]
  char v20[36]; // [sp+24h] [bp-24h] BYREF

  v16 = a1;
  v18 = a3;
  v19 = a4;
  v6 = 0;
  if ( a2 < 8 )
    return -1073741246;
  v7 = (int)(a1 + 2);
  v8 = a2 - 8;
  if ( (*a1 & 0xFFFFFF) != 5062989 )
    return -1073741672;
  if ( *a1 < 0 )
    return sub_510E10();
  v10 = a1[1];
  if ( a5 && v10 > *a5 )
    return -1073739516;
  v11 = (*(int (__fastcall **)(unsigned int))a6)(v10);
  v12 = v11;
  if ( v11 )
  {
    v13 = *((unsigned __int8 *)v16 + 3);
    v16 = (int *)v13;
    if ( (v13 & 0x7F) != 0 )
    {
      v14 = RtlGetCompressionWorkSpaceSize(v13 & 0x7F, v20, &v17);
      if ( v14 < 0 )
        goto LABEL_15;
      if ( v17 )
      {
        v6 = (*(int (**)(void))a6)();
        if ( !v6 )
        {
          v14 = -1073741670;
          goto LABEL_15;
        }
      }
      v14 = RtlDecompressBufferEx((unsigned __int8)v16 & 0x7F, v12, v10, v7, v8, &v15, v6);
      if ( v14 < 0 )
      {
LABEL_15:
        if ( v12 )
          (*(void (__fastcall **)(int))(a6 + 4))(v12);
        if ( v6 )
          (*(void (__fastcall **)(int))(a6 + 4))(v6);
        return v14;
      }
      if ( v10 == v15 )
      {
LABEL_14:
        *v18 = v12;
        v12 = 0;
        v14 = 0;
        *v19 = v10;
        goto LABEL_15;
      }
    }
    else if ( v8 == v10 )
    {
      memmove(v11, v7, v10);
      v15 = v10;
      goto LABEL_14;
    }
    v14 = -1073741246;
    goto LABEL_15;
  }
  return -1073741670;
}
