// BiUpdateObjectReferenceInEfiEntry 
 
int __fastcall BiUpdateObjectReferenceInEfiEntry(int a1, int a2)
{
  int v4; // r4
  int v5; // r6
  int v6; // r4
  int v7; // r0
  unsigned __int16 *v8; // r5
  char *v9; // r7
  unsigned int v10; // r8
  _DWORD v12[2]; // [sp+0h] [bp-40h] BYREF
  char v13[16]; // [sp+8h] [bp-38h] BYREF
  char v14[40]; // [sp+18h] [bp-28h] BYREF

  v4 = BiGetObjectReferenceFromEfiEntry(a1, v14);
  if ( v4 >= 0 )
  {
    v4 = BcdQueryObject(a2, 0, 0, (int)v13);
    if ( v4 >= 0 )
    {
      if ( memcmp((unsigned int)v14, (unsigned int)v13, 16) )
      {
        v5 = a1 + 28;
        v6 = *(_DWORD *)(a1 + 40);
        v7 = ExAllocatePoolWithTag(1, v6 - 20, 1262764866);
        v8 = (unsigned __int16 *)v7;
        if ( v7 )
        {
          memmove(v7, v5 + 20, v6 - 20);
          wcsupr(v8);
          v9 = wcsstr((char *)v8, (char *)L"BCDOBJECT=");
          if ( v9 )
          {
            v10 = wcslen(L"BCDOBJECT=");
            RtlInitUnicodeString((unsigned int)v12, 0);
            v4 = RtlStringFromGUIDEx((int)v13, (int)v12, 1);
            if ( v4 >= 0 )
            {
              memmove(v5 + 2 * (v10 + ((unsigned int)((v9 - (char *)v8) >> 1) >> 1) + 10), v12[1], LOWORD(v12[0]));
              RtlFreeAnsiString(v12);
            }
          }
          else
          {
            v4 = -1073741275;
          }
          ExFreePoolWithTag((unsigned int)v8);
        }
        else
        {
          v4 = -1073741670;
        }
      }
    }
  }
  return v4;
}
