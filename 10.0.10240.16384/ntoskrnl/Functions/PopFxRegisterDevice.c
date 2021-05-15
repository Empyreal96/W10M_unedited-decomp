// PopFxRegisterDevice 
 
int __fastcall PopFxRegisterDevice(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _DWORD *a9)
{
  int v12; // r8
  int v13; // r0
  int v14; // r7
  _DWORD *v15; // r6
  int v16; // r5
  __int64 v17; // r0
  int result; // r0

  v12 = IoGetDeviceAttachmentBaseRef(a1);
  if ( v12 )
  {
    v13 = IoGetAttachedDeviceReference(a1);
    v14 = v13;
    if ( v13 )
    {
      v15 = *(_DWORD **)(*(_DWORD *)(v12 + 176) + 20);
      if ( v15 )
      {
        if ( (v15[42] & 1) != 0 )
        {
          v16 = PopFxRegisterDeviceWorker(v15[18], v15 + 40, a2, a3, a4, a5, (char)(*(_BYTE *)(v13 + 48) + 1));
          if ( v16 >= 0 )
          {
            MEMORY[0x1C] = v15;
            if ( v15[10] )
              sub_8125B4();
            PopFxAssignDeviceToDevNode((int)v15, 0);
            ObfReferenceObject(a1);
            MEMORY[0x34] = a1;
            MEMORY[0x38] = v14;
            v17 = PopFxTraceDeviceRegistration(0, 0);
            PopFxInsertDevice(v17, SHIDWORD(v17), 0);
            v14 = 0;
            v12 = 0;
            v16 = 0;
          }
        }
        else
        {
          v16 = -1073741661;
        }
      }
      else
      {
        v16 = -1073741811;
      }
      if ( v14 )
        JUMPOUT(0x8125C2);
    }
    else
    {
      v16 = -1073741811;
    }
    if ( v12 )
      ObfDereferenceObject(v12);
  }
  else
  {
    v16 = -1073741811;
  }
  result = v16;
  *a9 = 0;
  return result;
}
