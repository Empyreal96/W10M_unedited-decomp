// PiDevCfgCopyObjectProperties 
 
int __fastcall PiDevCfgCopyObjectProperties(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v10; // r0
  int v11; // r4
  int v12; // r8
  int v13; // r6
  unsigned int v14; // r7
  int v15; // r5
  int v16; // r0
  int v17; // r2
  int v18; // [sp+4h] [bp-54h]
  unsigned int v19; // [sp+20h] [bp-38h] BYREF
  unsigned int v20; // [sp+24h] [bp-34h] BYREF
  unsigned int v21; // [sp+28h] [bp-30h]
  int v22; // [sp+2Ch] [bp-2Ch] BYREF
  int v23; // [sp+30h] [bp-28h] BYREF
  int v24; // [sp+34h] [bp-24h]
  int v25; // [sp+38h] [bp-20h]

  v24 = 0;
  v25 = a4;
  v22 = 0;
  v23 = 1;
  v19 = 0;
  v20 = 0;
  if ( !a4 )
    return sub_7E5258();
  if ( a7 || (v11 = PnpOpenObjectRegKey(a1, a5, a6, 33554433, 0, (int)&v22, 0, 0), v11 >= 0) )
  {
    v10 = PnpGetGenericStorePropertyKeys(a1, a4, 0, 0, 0, 0, &v19);
    v11 = v10;
    if ( v10 >= 0 || v10 == -1073741789 )
    {
      if ( v19 )
      {
        v12 = ExAllocatePoolWithTag(1, 20 * v19, 1667526736);
        if ( v12 )
        {
          v11 = PnpGetGenericStorePropertyKeys(a1, a4, 0, 0, v12, v19, &v19);
          if ( v11 >= 0 )
          {
            v21 = 256;
            v13 = ExAllocatePoolWithTag(1, 256, 1667526736);
            if ( v13 )
            {
              v14 = 0;
              if ( v19 )
              {
                v15 = v12;
                do
                {
                  v16 = PnpGetGenericStoreProperty(a1, v25, 0, v15, &v23, v13, v21, &v20);
                  v11 = v16;
                  if ( v16 == -1073741789 )
                  {
                    if ( v20 <= v21 )
                    {
                      v11 = -1073741595;
                      break;
                    }
                    ExFreePoolWithTag(v13);
                    v21 = v20;
                    v13 = ExAllocatePoolWithTag(1, v20, 1667526736);
                    if ( !v13 )
                    {
                      v11 = -1073741670;
                      break;
                    }
                    v11 = 0;
                    --v14;
                    v15 -= 20;
                  }
                  else
                  {
                    if ( v16 < 0 )
                      break;
                    v17 = a7 ? a7 : v22;
                    v11 = PiDevCfgSetObjectProperty(a1, 0, a5, a6, v17, v18, v15, v23, v13, v20);
                    if ( v11 < 0 )
                      break;
                  }
                  ++v14;
                  v15 += 20;
                }
                while ( v14 < v19 );
              }
              if ( v13 )
                ExFreePoolWithTag(v13);
            }
            else
            {
              v11 = -1073741670;
            }
          }
          ExFreePoolWithTag(v12);
        }
        else
        {
          v11 = -1073741670;
        }
      }
      else
      {
        v11 = 0;
      }
    }
  }
  if ( v24 )
    ZwClose();
  if ( v22 )
    ZwClose();
  return v11;
}
