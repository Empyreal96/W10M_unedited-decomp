// PfpParametersInitialize 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PfpParametersInitialize(int a1)
{
  int (__fastcall *v2)(_DWORD *); // r3
  int result; // r0
  int v4; // r2
  int v5; // r0
  unsigned int v6; // [sp+10h] [bp-38h] BYREF
  char v7[8]; // [sp+18h] [bp-30h] BYREF
  char v8[8]; // [sp+20h] [bp-28h] BYREF
  int v9; // [sp+28h] [bp-20h]
  int v10; // [sp+2Ch] [bp-1Ch]
  char *v11; // [sp+30h] [bp-18h]
  int v12; // [sp+34h] [bp-14h]
  int v13; // [sp+38h] [bp-10h]
  int v14; // [sp+3Ch] [bp-Ch]

  memset((_BYTE *)a1, 0, 496);
  v2 = PfpParametersWatcher;
  *(_DWORD *)(a1 + 472) = 0;
  *(_QWORD *)(a1 + 24) = *(_QWORD *)(&a1 - 1);
  *(_DWORD *)(a1 + 16) = 0;
  memset((_BYTE *)(a1 + 36), 0, 28);
  *(_DWORD *)(a1 + 36) = 0x80000000;
  *(_DWORD *)(a1 + 48) = 16;
  *(_DWORD *)(a1 + 44) = 64;
  *(_DWORD *)(a1 + 52) = 5000;
  *(_DWORD *)(a1 + 56) = 10000;
  *(_DWORD *)(a1 + 60) = 10000;
  PfSnParametersSetDefaults(a1);
  RtlInitUnicodeString((unsigned int)v7, L"\\KernelObjects\\SuperfetchParametersChanged");
  PfpCreateEvent((int)v7, 1, (_DWORD *)a1);
  RtlInitUnicodeString(
    (unsigned int)v8,
    L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Session Manager\\Memory Management\\PrefetchParameters");
  v9 = 24;
  v10 = 0;
  v12 = 576;
  v11 = v8;
  v13 = 0;
  v14 = 0;
  result = ZwCreateKey();
  if ( result < 0 )
  {
    *(_DWORD *)(a1 + 4) = 0;
  }
  else
  {
    PfpParametersRead((_DWORD *)a1);
    PfSnParametersRead(a1);
    v6 = 4;
    if ( PfpGetParameter(*(_DWORD *)(a1 + 4), L"BootId", 4, a1 + 40, &v6) < 0 )
      *(_DWORD *)(a1 + 40) = 0;
    v5 = *(_DWORD *)(a1 + 4);
    ++*(_DWORD *)(a1 + 40);
    PfpSetParameter(v5, L"BootId", v4, a1 + 40);
    result = PfpSetBaseTime(*(_DWORD *)(a1 + 4), (_DWORD *)(a1 + 492));
  }
  return result;
}
