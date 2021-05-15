// PopBcdSetDefaultResumeObjectElements 
 
int __fastcall PopBcdSetDefaultResumeObjectElements(int a1, int a2)
{
  unsigned __int16 *v4; // r6
  unsigned int v5; // r7
  int v6; // r4
  int v7; // r9
  int v8; // r2
  int v9; // r0
  int v10; // r2
  int v11; // r0
  int v12; // r2
  int v13; // r0
  unsigned __int16 *v14; // r0
  __int16 *v15; // r4
  int v16; // r10
  int v17; // r8
  int v18; // r0
  unsigned int v19; // r0
  int v20; // r2
  int v21; // r2
  int v22; // r2
  int v23; // r4
  int v24; // r2
  __int16 v26; // [sp+8h] [bp-50h] BYREF
  char v27[2]; // [sp+Ah] [bp-4Eh] BYREF
  char v28[4]; // [sp+Ch] [bp-4Ch] BYREF
  int v29; // [sp+10h] [bp-48h] BYREF
  unsigned __int16 *v30; // [sp+14h] [bp-44h] BYREF
  int v31; // [sp+18h] [bp-40h] BYREF
  int v32; // [sp+1Ch] [bp-3Ch] BYREF
  int v33; // [sp+20h] [bp-38h]
  int v34; // [sp+24h] [bp-34h]
  int v35; // [sp+28h] [bp-30h]
  char v36[40]; // [sp+30h] [bp-28h] BYREF

  v29 = 0;
  v31 = 0;
  v32 = 0;
  v4 = 0;
  v30 = 0;
  v5 = 0;
  v6 = PopBcdReadElement(a2, 0x11000001u, (unsigned int *)&v29, &v31);
  v7 = v29;
  if ( v6 >= 0 )
  {
    v6 = PopBcdReadElement(a2, 0x12000002u, (unsigned int *)&v30, &v32);
    if ( v6 < 0 )
    {
      v4 = v30;
    }
    else
    {
      v32 = 8;
      v9 = BcdGetElementDataWithFlags(a2, 0x15000052u, v8, (int)v36, &v32);
      v29 = 2;
      v33 = v9;
      v11 = BcdGetElementDataWithFlags(a2, 0x16000054u, v10, (int)v27, &v29);
      v29 = 2;
      v34 = v11;
      v13 = BcdGetElementDataWithFlags(a2, 0x16000046u, v12, (int)v28, &v29);
      v4 = v30;
      v35 = v13;
      v14 = wcsrchr(v30, 92);
      if ( v14 )
      {
        if ( dword_61A1F0 == 2 )
          v15 = L"winresume.efi";
        else
          v15 = L"winresume.exe";
        v16 = ((char *)v14 - (char *)v4 + 2) >> 1;
        v17 = 2 * (wcslen((unsigned __int16 *)v15) + v16 + 1);
        v18 = ExAllocatePoolWithTag(1, v17, 1684226640);
        v5 = v18;
        if ( v18 )
        {
          memmove(v18, (int)v4, 2 * v16);
          v19 = wcslen((unsigned __int16 *)v15);
          memmove(v5 + 2 * v16, (int)v15, 2 * (v19 + 1));
          v6 = BcdSetElementDataWithFlags(a1, 0x11000001u, v20, v7, v31);
          if ( v6 >= 0 )
          {
            v6 = BcdSetElementDataWithFlags(a1, 0x12000002u, v21, v5, v17);
            if ( v6 >= 0 )
            {
              if ( v33 >= 0 )
                BcdSetElementDataWithFlags(a1, 0x15000052u, v22, (int)v36, v32);
              v23 = v29;
              if ( v34 >= 0 )
                BcdSetElementDataWithFlags(a1, 0x16000054u, v22, (int)v27, v29);
              if ( v35 >= 0 )
                BcdSetElementDataWithFlags(a1, 0x16000046u, v22, (int)v28, v23);
              v6 = PopBcdSetupResumeObject(a1);
              if ( v6 >= 0 )
              {
                HIBYTE(v26) = 0;
                LOBYTE(v26) = KdDebuggerEnabled != 0;
                v6 = BcdSetElementDataWithFlags(a1, 0x26000006u, v24, (int)&v26, 2);
                if ( v6 >= 0 )
                  v6 = 0;
              }
            }
          }
        }
        else
        {
          v6 = -1073741670;
        }
      }
      else
      {
        v6 = -1073741788;
      }
    }
  }
  if ( v7 )
    ExFreePoolWithTag(v7);
  if ( v4 )
    ExFreePoolWithTag((unsigned int)v4);
  if ( v5 )
    ExFreePoolWithTag(v5);
  return v6;
}
