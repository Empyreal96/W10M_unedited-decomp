// WheapWmiExecuteErrorSourceMethod 
 
int __fastcall WheapWmiExecuteErrorSourceMethod(int a1, unsigned int a2, int *a3, unsigned int a4, unsigned int *a5)
{
  int result; // r0
  unsigned int v7; // r4
  int *v8; // r0
  int (__fastcall **v9)(char *); // r3
  char *v10; // r0
  int *v11; // r0
  int *v12; // r3
  int v13; // r5
  int v14; // r9
  unsigned int v15; // r8
  unsigned int *v16; // r10
  _DWORD *v17; // r2
  int *v18; // r10
  _DWORD *v19; // [sp+0h] [bp-400h]
  unsigned int *v20; // [sp+Ch] [bp-3F4h]
  char v21[1008]; // [sp+10h] [bp-3F0h] BYREF

  switch ( a1 )
  {
    case 1:
      v7 = 0;
      if ( !dword_641930 )
        goto LABEL_32;
      v7 = 972 * dword_641930 + 12;
      if ( v7 > a2 )
        goto LABEL_34;
      *a3 = 0;
      v13 = (int)(a3 + 3);
      v14 = 0;
      v15 = 0;
      v16 = (unsigned int *)(a3 + 1);
      v17 = a3 + 2;
      v20 = (unsigned int *)(v13 - 8);
      v19 = (_DWORD *)(v13 - 4);
      if ( (int *)dword_641934 != &dword_641934 )
      {
        v18 = (int *)dword_641934;
        do
        {
          if ( v15 >= dword_641930 )
            break;
          memmove(v13, (int)v18 + 73, 0x3CCu);
          v18 = (int *)*v18;
          v13 += 972;
          v14 += 972;
          ++v15;
        }
        while ( v18 != &dword_641934 );
        v16 = v20;
        v17 = v19;
      }
      *v16 = v15;
      *v17 = v14;
      goto LABEL_41;
    case 2:
      v7 = 0;
      if ( !dword_641930 )
        goto LABEL_32;
      if ( a4 < 4 )
        goto LABEL_27;
      v7 = 980;
      if ( a2 < 0x3D4 )
        goto LABEL_34;
      v12 = WheapGetErrorSource((int)&WheapErrorSourceTable, *a3);
      if ( !v12 )
        goto LABEL_32;
      *a3 = 0;
      a3[1] = 972;
      memmove((int)(a3 + 2), (int)v12 + 73, 0x3CCu);
LABEL_41:
      result = 0;
      goto LABEL_42;
    case 3:
      v7 = 0;
      if ( a4 >= 0x3D0 )
      {
        v7 = 4;
        if ( a2 < 4 )
          goto LABEL_34;
        if ( *a3 == 972 )
        {
          memmove((int)v21, (int)(a3 + 1), 0x3CCu);
          v9 = (int (__fastcall **)(char *))&PshedSetErrorSourceInfo;
          v10 = v21;
          goto LABEL_23;
        }
        v7 = 0;
      }
      goto LABEL_27;
    case 4:
      v7 = 0;
      if ( a4 >= 4 )
      {
        v7 = 4;
        if ( a2 >= 4 )
        {
          v11 = WheapGetErrorSource((int)&WheapErrorSourceTable, *a3);
          if ( v11 )
          {
            if ( *(int *)((char *)v11 + 85) != 2 )
            {
              v9 = (int (__fastcall **)(char *))&PshedEnableErrorSource;
              v10 = (char *)v11 + 73;
              goto LABEL_23;
            }
LABEL_16:
            result = 0;
LABEL_24:
            *a3 = result;
            goto LABEL_42;
          }
LABEL_32:
          result = -1073741275;
          goto LABEL_42;
        }
LABEL_34:
        result = -1073741789;
        goto LABEL_42;
      }
LABEL_27:
      result = -1073741811;
      goto LABEL_42;
    case 5:
      v7 = 0;
      if ( a4 >= 4 )
      {
        v7 = 4;
        if ( a2 >= 4 )
        {
          v8 = WheapGetErrorSource((int)&WheapErrorSourceTable, *a3);
          if ( v8 )
          {
            if ( *(int *)((char *)v8 + 85) != 1 )
            {
              v9 = (int (__fastcall **)(char *))&PshedDisableErrorSource;
              v10 = (char *)v8 + 73;
LABEL_23:
              result = (*v9)(v10);
              goto LABEL_24;
            }
            goto LABEL_16;
          }
          goto LABEL_32;
        }
        goto LABEL_34;
      }
      goto LABEL_27;
  }
  result = -1073741161;
  v7 = 0;
LABEL_42:
  *a5 = v7;
  return result;
}
