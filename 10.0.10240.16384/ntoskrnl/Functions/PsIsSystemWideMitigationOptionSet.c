// PsIsSystemWideMitigationOptionSet 
 
BOOL __fastcall PsIsSystemWideMitigationOptionSet(char a1, int a2, int a3, int a4)
{
  return ((15 << a1) & PspSystemMitigationOptions) == ((1 << (a1 + 2)) | a3)
      && (dword_68259C & ((0xFu >> (32 - a1)) | (15 << (a1 - 32)))) == ((1 << (a1 - 30)) | a4);
}
