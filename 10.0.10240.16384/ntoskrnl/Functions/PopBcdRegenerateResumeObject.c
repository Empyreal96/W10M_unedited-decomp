// PopBcdRegenerateResumeObject 
 
int __fastcall PopBcdRegenerateResumeObject(int a1, int a2, int *a3)
{
  unsigned int v5; // r7
  int v6; // r4
  unsigned int v7; // r8
  int v8; // r6
  int v9; // r2
  int v10; // r2
  int v11; // r2
  int v13; // [sp+8h] [bp-60h] BYREF
  int v14; // [sp+Ch] [bp-5Ch] BYREF
  int v15; // [sp+10h] [bp-58h] BYREF
  unsigned int v16; // [sp+14h] [bp-54h] BYREF
  int v17; // [sp+18h] [bp-50h] BYREF
  int v18[2]; // [sp+20h] [bp-48h] BYREF
  _DWORD v19[4]; // [sp+28h] [bp-40h] BYREF
  char v20[48]; // [sp+38h] [bp-30h] BYREF

  v15 = 0;
  v16 = 0;
  v17 = 0;
  v13 = 0;
  v18[0] = 1;
  v18[1] = 270532612;
  v5 = 0;
  v14 = 0;
  v6 = BcdCreateObject(a1, 0, (int)v18, (int)&v13);
  if ( v6 < 0 )
  {
    v8 = v13;
  }
  else
  {
    v6 = PopBcdReadElement(a2, 0x12000004u, &v16, &v15);
    v7 = v16;
    if ( v6 < 0 )
    {
      v8 = v13;
    }
    else
    {
      PopBcdReadElement(a2, 0x12000005u, (unsigned int *)&v14, &v17);
      v8 = v13;
      v6 = BcdSetElementDataWithFlags(v13, 0x12000004u, v9, v7, v15);
      v5 = v14;
      if ( v6 >= 0 )
      {
        if ( !v14 || (v6 = BcdSetElementDataWithFlags(v8, 0x12000005u, v10, v14, v17), v6 >= 0) )
        {
          v6 = PopBcdSetDefaultResumeObjectElements(v8, a2);
          if ( v6 >= 0 )
          {
            v19[0] = 452631625;
            v19[1] = 1247549099;
            v19[2] = 673258384;
            v19[3] = 1620367874;
            v6 = BcdSetElementDataWithFlags(v8, 0x14000006u, 673258384, (int)v19, 16);
            if ( v6 >= 0 )
            {
              v6 = BcdQueryObject(v8, 0, 0, v20);
              if ( v6 >= 0 )
              {
                v6 = BcdSetElementDataWithFlags(a2, 0x23000003u, v11, (int)v20, 16);
                if ( v6 >= 0 )
                {
                  *a3 = v8;
                  v8 = 0;
                }
              }
            }
          }
        }
      }
    }
    if ( v7 )
      ExFreePoolWithTag(v7);
    if ( v5 )
      ExFreePoolWithTag(v5);
  }
  if ( v8 )
  {
    if ( v6 < 0 )
      BcdDeleteObject(v8);
    else
      BcdCloseObject(v8);
  }
  return v6;
}
