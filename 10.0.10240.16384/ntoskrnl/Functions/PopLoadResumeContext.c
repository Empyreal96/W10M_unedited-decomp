// PopLoadResumeContext 
 
int __fastcall PopLoadResumeContext(int a1)
{
  int v2; // r4
  int v3; // r5
  int v4; // r8
  unsigned int v5; // r6
  int v6; // r0
  int v7; // r7
  unsigned int v8; // r3
  int v10; // [sp+8h] [bp-28h]
  int v11; // [sp+Ch] [bp-24h] BYREF
  char v12[32]; // [sp+10h] [bp-20h] BYREF

  v11 = 0;
  v2 = 0;
  v3 = PopOpenKey(&v11, L"Control\\Winresume");
  if ( v3 < 0 )
    return v3;
  RtlInitUnicodeString((unsigned int)v12, L"ResumeContext");
  v4 = v11;
  v3 = ZwQueryValueKey();
  if ( v3 == -1073741789 )
  {
    v2 = ExAllocatePoolWithTag(1, v10, 2020885330);
    if ( !v2 )
      goto LABEL_4;
    v3 = ZwQueryValueKey();
  }
  if ( v3 < 0 )
    goto LABEL_11;
  v5 = (*(_DWORD *)(v2 + 8) + 4095) & 0xFFFFF000;
  v6 = ExAllocatePoolWithTag(512, v5, 2020885330);
  v7 = v6;
  if ( v6 )
  {
    memmove(v6, v2 + 12, *(_DWORD *)(v2 + 8));
    v8 = *(_DWORD *)(v2 + 8);
    if ( v5 > v8 )
      memset((_BYTE *)(v8 + v7), 0, v5 - v8);
    *(_DWORD *)(a1 + 152) = v7;
    *(_DWORD *)(a1 + 156) = v5 >> 12;
    goto LABEL_11;
  }
LABEL_4:
  v3 = -1073741801;
LABEL_11:
  if ( v4 )
    ZwClose();
  if ( v2 )
    ExFreePoolWithTag(v2);
  return v3;
}
