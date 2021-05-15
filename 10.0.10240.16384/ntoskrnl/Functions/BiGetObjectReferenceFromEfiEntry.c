// BiGetObjectReferenceFromEfiEntry 
 
int __fastcall BiGetObjectReferenceFromEfiEntry(int a1, _BYTE *a2)
{
  int v4; // r6
  int v5; // r0
  unsigned __int16 *v6; // r5
  char *v7; // r0
  int v8; // r4
  unsigned __int16 v10[4]; // [sp-4h] [bp-70h] BYREF
  unsigned __int16 v11[52]; // [sp+4h] [bp-68h] BYREF

  if ( !BiIsWindowsEfiEntry() )
    return -1073741811;
  v4 = *(_DWORD *)(a1 + 40) - 20;
  v5 = ExAllocatePoolWithTag(1, v4, 1262764866);
  v6 = (unsigned __int16 *)v5;
  if ( !v5 )
    return -1073741670;
  memmove(v5, a1 + 48, v4);
  wcsupr(v6);
  v7 = wcsstr((char *)v6, (char *)L"BCDOBJECT=");
  if ( v7 && (unsigned int)v6 + v4 - (_DWORD)(v7 + 20) >= 0x4E )
  {
    memmove((int)v11, (int)(v7 + 20), 0x4Eu);
    v11[38] = 0;
    RtlInitUnicodeString((unsigned int)v10, v11);
    v8 = RtlGUIDFromString(v10, a2);
  }
  else
  {
    v8 = -1073741275;
  }
  ExFreePoolWithTag((unsigned int)v6);
  return v8;
}
