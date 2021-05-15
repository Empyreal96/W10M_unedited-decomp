// PopBcdSetupResumeObject 
 
int __fastcall PopBcdSetupResumeObject(int a1, int a2, int a3, int a4)
{
  int v5; // r7
  _BYTE *v6; // r0
  _DWORD *v7; // r5
  int v8; // r4
  int v9; // r2
  int v10; // r2
  int v12; // [sp+8h] [bp-18h] BYREF
  int v13; // [sp+Ch] [bp-14h]

  v12 = a3;
  v13 = a4;
  v5 = (unsigned __int16)IoArcBootDeviceName + 22;
  v6 = (_BYTE *)ExAllocatePoolWithTag(1, v5, 1684226640);
  v7 = v6;
  if ( !v6 )
    return -1073741670;
  memset(v6, 0, v5);
  *v7 = 2;
  memmove((int)(v7 + 5), dword_9209CC, (unsigned __int16)IoArcBootDeviceName);
  v8 = BcdSetElementDataWithFlags(a1, 0x21000001u, v9, (int)v7, v5);
  if ( v8 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)&v12, L"\\hiberfil.sys");
    v8 = BcdSetElementDataWithFlags(a1, 0x22000002u, v10, v13, (unsigned __int16)v12 + 2);
  }
  ExFreePoolWithTag((unsigned int)v7);
  return v8;
}
