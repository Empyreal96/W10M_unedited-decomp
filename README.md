# W10M_unedited-decomp
Pure Hex-rays Decompiler Psudocode of various Windows 10 Mobile Binaries, No edit have been done to the output this is a TEMPLATE repository, you will need to piece together each function, class etc..

*Expect no fix-ups or edits from me, I have nor the time, or the Knowledge to do so!*



**If you need a brief explanation to what this is:**

- It is **NOT** compliable code yet.
- This is from IDA Pro 7.5 with ARM plugins, some psudocode may be inaccurate.
- Disassembled `.ASM` files will be present for those with skills to use it.
- Functions were decompiled and files named with the aid of [IDAFunctionsDecompiler](https://github.com/JCGdev/IDAFunctionsDecompiler)
- If any functions failed to decompile, check the ERROR .txt in the `Functions` folder



Currenty in repo:

- Ntoskrnl - 10.0.1024.16384



Example of Psudocode in this repo:

```c
// KiBugCheckProgress 
 
int __fastcall KiBugCheckProgress(unsigned int a1)
{
  BOOL v2; // r5
  unsigned __int16 *v4; // [sp+0h] [bp-30h] BYREF
  unsigned __int16 *v5; // [sp+4h] [bp-2Ch]
  unsigned __int16 *v6; // [sp+8h] [bp-28h]
  unsigned __int16 v7; // [sp+Ch] [bp-24h]
  __int16 v8; // [sp+Eh] [bp-22h]
  char *v9; // [sp+10h] [bp-20h]
  char v10; // [sp+18h] [bp-18h] BYREF

  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = 8;
  v9 = &v10;
  v2 = IopAutoReboot != 0;
  BgpFwAcquireLock(a1);
  if ( (dword_619018 & 2) != 0 )
    BgpFwDisplayBugCheckProgressUpdate(a1, &v4, v2);
  BgpFwReleaseLock();
  if ( a1 )
  {
    KiHeadlessDisplayString(L"\r\x1B[0K\r", 14);
    if ( v4 )
    {
      if ( v5 && v6 )
      {
        KiHeadlessDisplayString(*((_DWORD *)v4 + 1), *v4);
        KiHeadlessDisplayString(L" ", 4);
        KiHeadlessDisplayString(*((_DWORD *)v5 + 1), *v5);
        KiHeadlessDisplayString(v9, v7);
        KiHeadlessDisplayString(*((_DWORD *)v6 + 1), *v6);
      }
    }
  }
  if ( a1 == 100 )
    KiHeadlessDisplayString(L"\r\n", 6);
  return 0;
}

```

