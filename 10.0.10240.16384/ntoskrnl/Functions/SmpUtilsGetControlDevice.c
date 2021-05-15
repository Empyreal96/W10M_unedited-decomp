// SmpUtilsGetControlDevice 
 
int __fastcall SmpUtilsGetControlDevice(int a1, _DWORD *a2, int *a3)
{
  int v5; // r5
  _DWORD *v6; // r4
  _DWORD *v8; // [sp+24h] [bp-3Ch] BYREF
  char v9[8]; // [sp+28h] [bp-38h] BYREF
  int v10; // [sp+38h] [bp-28h]
  int v11; // [sp+3Ch] [bp-24h]
  char *v12; // [sp+40h] [bp-20h]
  int v13; // [sp+44h] [bp-1Ch]
  int v14; // [sp+48h] [bp-18h]
  int v15; // [sp+4Ch] [bp-14h]

  RtlInitUnicodeString((unsigned int)v9, L"\\Device\\RdyBoost");
  v10 = 24;
  v11 = 0;
  v13 = 576;
  v12 = v9;
  v14 = 0;
  v15 = 0;
  v5 = ZwCreateFile();
  if ( v5 >= 0 )
  {
    v5 = ObReferenceObjectByHandle(0, 3, 0, 0, (int)&v8, 0);
    v6 = v8;
    if ( v5 >= 0 )
    {
      *a3 = IoGetRelatedDeviceObject(v8);
      *a2 = 0;
      v5 = 0;
    }
    if ( v6 )
      ObfDereferenceObject((int)v6);
  }
  return v5;
}
