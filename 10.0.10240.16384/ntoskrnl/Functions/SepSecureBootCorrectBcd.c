// SepSecureBootCorrectBcd 
 
int SepSecureBootCorrectBcd()
{
  int v0; // r4
  int v1; // r6
  int v2; // r0
  int v3; // r0
  unsigned int v4; // r7
  unsigned int v5; // r9
  unsigned int v6; // r10
  unsigned int v7; // r8
  int v9; // r5
  int v10; // [sp+8h] [bp-38h] BYREF
  int v11; // [sp+Ch] [bp-34h] BYREF
  int v12[2]; // [sp+10h] [bp-30h] BYREF
  int v13[10]; // [sp+18h] [bp-28h] BYREF

  v10 = 0;
  v11 = 0;
  v12[0] = 0;
  v13[0] = 0;
  v0 = BcdOpenSystemStore((int)v13);
  v1 = v13[0];
  if ( v0 >= 0 )
  {
    v13[0] = 1;
    v13[1] = 0;
    v2 = BcdEnumerateObjects(v1, v13, 0, &v11, v12);
    v0 = v2;
    if ( v2 < 0 && v2 == -1073741789 )
    {
      v3 = ExAllocatePoolWithTag(1, v11, 1649632595);
      v4 = v3;
      if ( v3 )
      {
        v0 = BcdEnumerateObjects(v1, v13, v3, &v11, v12);
        if ( v0 >= 0 )
        {
          v5 = v12[0];
          v6 = 0;
          if ( v12[0] )
          {
            v7 = v4;
            while ( 1 )
            {
              v0 = BcdOpenObject(v1, v7, &v10);
              if ( v0 < 0 )
                break;
              v13[0] = 0;
              if ( *(_WORD *)(dword_641874 + 36) )
                return sub_813830();
              BcdCloseObject(v10);
              v9 = 0;
              ++v6;
              v10 = 0;
              v7 += 20;
              if ( v6 >= v5 )
                goto LABEL_12;
            }
            v9 = v10;
LABEL_12:
            if ( v9 )
              BcdCloseObject(v9);
          }
        }
        ExFreePoolWithTag(v4);
      }
      else
      {
        v0 = -1073741801;
      }
    }
  }
  if ( v1 )
    BcdCloseStore(v1);
  return v0;
}
