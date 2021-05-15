// EtwpReceiveReplyDataBlock 
 
int __fastcall EtwpReceiveReplyDataBlock(int *a1, unsigned int a2, _DWORD *a3)
{
  int v4; // r6
  int v6; // r0
  int v8; // r4
  int *v9; // r7
  int *v10; // r5
  unsigned int v11; // r6
  unsigned int v12; // r2
  int *v14[2]; // [sp+8h] [bp-30h] BYREF
  __int64 v15[5]; // [sp+10h] [bp-28h] BYREF

  *a3 = 0;
  v4 = a1[1];
  v6 = *a1;
  v15[0] = *(_QWORD *)EtwpOneMs * (unsigned int)v4;
  v8 = ObReferenceObjectByHandle(v6, 4, EtwpRegistrationObjectType, 1, (int)v14, 0);
  if ( v8 >= 0 )
  {
    v9 = v14[0];
    if ( (*((_BYTE *)v14[0] + 50) & 4) != 0 )
    {
      KeRemoveQueueEx(v14[0][6], 1, 0, v15, v14, 1u);
      v10 = v14[0];
      if ( v14[0] == (int *)258 || v14[0] == (int *)192 )
      {
        v8 = (int)v14[0];
      }
      else
      {
        v11 = v14[0][2];
        v12 = *(_DWORD *)(v11 + 4);
        if ( v12 > a2 )
        {
          v8 = -1073741789;
        }
        else
        {
          memmove((int)a1, v14[0][2], v12);
          v8 = 0;
        }
        *a3 = *(_DWORD *)(v11 + 4);
        EtwpUnreferenceDataBlock(v11);
        ExFreePoolWithTag((unsigned int)v10);
      }
    }
    else
    {
      v8 = -1073741816;
    }
    ObfDereferenceObject((int)v9);
  }
  return v8;
}
