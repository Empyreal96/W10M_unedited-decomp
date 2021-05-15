// MiCompactServiceTable 
 
int __fastcall MiCompactServiceTable(int a1, unsigned int *a2)
{
  int v4; // r4
  int v5; // r6
  int v6; // r3
  int v8; // r3
  int v9; // r3
  unsigned int *v10; // r9
  unsigned int v11; // r7
  int *v12; // [sp+0h] [bp-28h] BYREF
  unsigned int *v13; // [sp+4h] [bp-24h] BYREF
  unsigned __int8 *v14[8]; // [sp+8h] [bp-20h] BYREF

  v12 = (int *)a1;
  v13 = a2;
  v14[0] = (unsigned __int8 *)1441812;
  v14[1] = (unsigned __int8 *)L"win32k.sys";
  v4 = 0;
  v5 = 0;
  if ( RtlEqualUnicodeString((unsigned __int16 *)(a1 + 44), (unsigned __int16 *)v14, 1) == 1 )
  {
    if ( LookupEntryPoint(*(_DWORD *)(a1 + 24), (int)"W32pServiceTable", &v12, v6) < 0
      || LookupEntryPoint(*(_DWORD *)(a1 + 24), (int)"W32pServiceLimit", &v13, v8) < 0
      || (v4 = LookupEntryPoint(*(_DWORD *)(a1 + 24), (int)"W32pArgumentTable", v14, v9), v4 < 0) )
    {
      __debugbreak();
    }
    v10 = v13;
    v11 = *v13;
    MiSetImageProtection(a1, (unsigned int)v12, 4 * *v13);
    if ( a2 == (unsigned int *)1 )
    {
      MiFinalizeDriverImage(a1);
      v5 = 1;
    }
    KeCompactServiceTable(v12, v14[0], *v10, 1);
    if ( *(_DWORD *)(MiSectionControlArea(*(_DWORD *)(a1 + 60)) + 88) )
      MiSetImageProtection(a1, (unsigned int)v12, 4 * v11);
  }
  if ( !v5 && a2 == (unsigned int *)1 )
    MiFinalizeDriverImage(a1);
  return v4;
}
