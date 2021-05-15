// sub_811DBC 
 
void __fastcall sub_811DBC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char a9, int a10, int a11, int a12, char a13, int a14, int a15, int a16, int a17, int a18, char a19, int a20, int a21, int a22, int a23, __int128 a24, unsigned __int16 a25)
{
  _DWORD *v25; // r6
  int v26; // r5
  int i; // r7
  _BYTE *v28; // r0
  int v29; // r0
  int v30; // r5

  if ( a9 )
  {
    qmemcpy(&a24, "\\??\\x:", 12);
    WORD4(a24) = *(_WORD *)dword_63282C;
    RtlInitUnicodeString((unsigned int)&a19, (unsigned __int16 *)&a24);
    v26 = 32;
    for ( i = 0; ; i = 1 )
    {
      if ( v25 )
        ExFreePoolWithTag((unsigned int)v25);
      v28 = (_BYTE *)ExAllocatePoolWithTag(1, v26, 541545559);
      v25 = v28;
      if ( !v28 )
        goto LABEL_16;
      memset(v28, 0, v26);
      v29 = sub_8AB264(&a19, 5636096, 0, 0);
      if ( v29 >= 0 )
        break;
      if ( v29 != -2147483643 || i )
        goto LABEL_15;
      v26 += 24 * (*v25 - 1);
    }
    if ( *v25 == 1 )
    {
      RtlStringCchPrintfW(&a25, 0x104u, (int)L"\\??\\PhysicalDrive%u", v25[2]);
      RtlInitUnicodeString((unsigned int)&a13, &a25);
      a21 = 0;
      a22 = 0;
      a23 = 0;
      if ( sub_8AB264(&a13, 2954240, &a21, 12) >= 0 )
      {
        v30 = ExAllocatePoolWithTag(1, a16, 541545559);
        if ( v30 )
        {
          sub_8AB264(&a13, 2954240, &a21, 12);
          ExFreePoolWithTag(v30);
          if ( a10 )
            ObfDereferenceObject(a10);
        }
      }
    }
LABEL_15:
    ExFreePoolWithTag((unsigned int)v25);
  }
LABEL_16:
  JUMPOUT(0x7A2B92);
}
