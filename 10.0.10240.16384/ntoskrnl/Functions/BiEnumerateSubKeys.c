// BiEnumerateSubKeys 
 
int __fastcall BiEnumerateSubKeys(int a1, unsigned int *a2, unsigned int *a3)
{
  unsigned int v3; // r5
  unsigned int v4; // r9
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r10
  unsigned int v8; // r6
  int v9; // r1
  int v10; // r0
  int v11; // r8
  unsigned int v12; // r5
  int v13; // r0
  int v14; // r4
  _DWORD *v15; // r3
  int v16; // r0
  _WORD *v17; // r2
  _DWORD v19[2]; // [sp+Ch] [bp-7Ch] BYREF
  unsigned int v20; // [sp+14h] [bp-74h] BYREF
  unsigned int *v21; // [sp+18h] [bp-70h]
  unsigned int *v22; // [sp+1Ch] [bp-6Ch]
  int v23; // [sp+20h] [bp-68h]
  unsigned int *v24; // [sp+28h] [bp-60h]
  _DWORD *v25; // [sp+2Ch] [bp-5Ch]
  unsigned int *v26; // [sp+30h] [bp-58h]
  int v27; // [sp+34h] [bp-54h]
  unsigned int v28; // [sp+4Ch] [bp-3Ch]
  unsigned int v29; // [sp+50h] [bp-38h]

  v21 = a3;
  v22 = a2;
  v23 = a1;
  v27 = a1;
  v26 = a2;
  v24 = a3;
  v19[1] = 0;
  *a2 = 0;
  *a3 = 0;
  v3 = 0;
  v4 = 0;
  v5 = BiZwQueryKey();
  v6 = v5;
  if ( v5 >= 0 || v5 == -2147483643 )
  {
    v7 = v28;
    if ( v28 )
    {
      v8 = v29 + 2;
      if ( v29 + 2 < v29 )
      {
        v8 = -1;
        v19[0] = -1;
        v6 = -1073741675;
      }
      else
      {
        v19[0] = v29 + 2;
        v6 = 0;
      }
      if ( v6 >= 0 )
      {
        v6 = RtlULongLongToULong(v8 * v28, (v8 * (unsigned __int64)v28) >> 32, v19);
        v8 = v19[0];
      }
      v20 = 0;
      if ( v6 >= 0 )
      {
        v6 = RtlULongLongToULong(4 * v7, (unsigned __int64)v7 >> 30, &v20);
        if ( v6 >= 0 )
        {
          if ( v20 + v8 < v20 )
          {
            v9 = -1;
            v6 = -1073741675;
          }
          else
          {
            v9 = v20 + v8;
            v6 = 0;
          }
          if ( v6 >= 0 )
          {
            v10 = ExAllocatePoolWithTag(1, v9, 1262764866);
            v4 = v10;
            if ( v10 )
            {
              v20 = v10 + 4 * v7;
              v11 = v29 + 26;
              if ( v29 >= 0xFFFFFFE6 )
              {
                v11 = -1;
                v6 = -1073741675;
              }
              else
              {
                v6 = 0;
              }
              if ( v6 >= 0 )
              {
                v19[0] = ExAllocatePoolWithTag(1, v11, 1262764866);
                if ( v19[0] )
                {
                  v12 = 0;
                  v25 = (_DWORD *)v4;
                  while ( v12 < v7 )
                  {
                    v13 = BiZwEnumerateKey();
                    v6 = v13;
                    if ( v13 == -2147483622 )
                    {
                      if ( !v12 )
                        goto LABEL_31;
                      break;
                    }
                    if ( v13 < 0 )
                      goto LABEL_31;
                    v14 = v19[0];
                    if ( *(_DWORD *)(v19[0] + 12) + 2 > v8 )
                    {
                      v6 = -1073741789;
                      goto LABEL_31;
                    }
                    v15 = v25;
                    v16 = v20;
                    *v25 = v20;
                    v25 = v15 + 1;
                    memmove(v16, v14 + 16, *(_DWORD *)(v14 + 12));
                    v17 = (_WORD *)(v20 + *(_DWORD *)(v14 + 12));
                    *v17 = 0;
                    v20 = (unsigned int)(v17 + 1);
                    v8 = v8 - *(_DWORD *)(v14 + 12) - 2;
                    ++v12;
                  }
                  *v22 = v4;
                  *v21 = v12;
                  v6 = 0;
LABEL_31:
                  v3 = v19[0];
                }
                else
                {
                  v6 = -1073741670;
                  v3 = 0;
                }
              }
            }
            else
            {
              v6 = -1073741670;
            }
          }
        }
      }
    }
    else
    {
      v6 = 0;
    }
  }
  if ( v3 )
    ExFreePoolWithTag(v3);
  if ( v6 < 0 && v4 )
    ExFreePoolWithTag(v4);
  if ( v6 == -1073741443 )
    __debugbreak();
  return v6;
}
