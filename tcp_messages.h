#ifndef ES_TCP_MESSAGES
#define ES_TCP_MESSAGES

    static const char Message_HeartbeatRequest = 0x01;
    static const char Message_HeartbeatResponse = 0x02;

    static const char Message_Ping = 0x03;
    static const char Message_Pong = 0x04;

    static const char Message_PrepareAck = 0x05;
    static const char Message_CommitAck = 0x06;

    static const char Message_SlaveAssignment = 0x07;
    static const char Message_CloneAssignment = 0x08;

    static const char Message_SubscribeReplica = 0x10;
    static const char Message_ReplicaLogPositionAck = 0x11;
    static const char Message_CreateChunk = 0x12;
    static const char Message_RawChunkBulk = 0x13;
    static const char Message_DataChunkBulk = 0x14;
    static const char Message_ReplicaSubscriptionRetry = 0x15;
    static const char Message_ReplicaSubscribed = 0x16;


    //Client Messages

    static const char Message_WriteEvents = 0x82;
    static const char Message_WriteEventsCompleted = 0x83;

    static const char Message_TransactionStart = 0x84;
    static const char Message_TransactionStartCompleted = 0x85;
    static const char Message_TransactionWrite = 0x86;
    static const char Message_TransactionWriteCompleted = 0x87;
    static const char Message_TransactionCommit = 0x88;
    static const char Message_TransactionCommitCompleted = 0x89;

    static const char Message_DeleteStream = 0x8A;
    static const char Message_DeleteStreamCompleted = 0x8B;

    static const char Message_ReadEvent = 0xB0;
    static const char Message_ReadEventCompleted = 0xB1;
    static const char Message_ReadStreamEventsForward = 0xB2;
    static const char Message_ReadStreamEventsForwardCompleted = 0xB3;
    static const char Message_ReadStreamEventsBackward = 0xB4;
    static const char Message_ReadStreamEventsBackwardCompleted = 0xB5;
    static const char Message_ReadAllEventsForward = 0xB6;
    static const char Message_ReadAllEventsForwardCompleted = 0xB7;
    static const char Message_ReadAllEventsBackward = 0xB8;
    static const char Message_ReadAllEventsBackwardCompleted = 0xB9;

    static const char Message_SubscribeToStream = 0xC0;
    static const char Message_SubscriptionConfirmation = 0xC1;
    static const char Message_StreamEventAppeared = 0xC2;
    static const char Message_UnsubscribeFromStream = 0xC3;
    static const char Message_SubscriptionDropped = 0xC4;
    static const char Message_ConnectToPersistentSubscription = 0xC5;
    static const char Message_PersistentSubscriptionConfirmation = 0xC6;
    static const char Message_PersistentSubscriptionStreamEventAppeared = 0xC7;
    static const char Message_CreatePersistentSubscription = 0xC8;
    static const char Message_CreatePersistentSubscriptionCompleted = 0xC9;
    static const char Message_DeletePersistentSubscription = 0xCA;
    static const char Message_DeletePersistentSubscriptionCompleted = 0xCB;
    static const char Message_PersistentSubscriptionAckEvents = 0xCC;
    static const char Message_PersistentSubscriptionNakEvents = 0xCD;
    static const char Message_UpdatePersistentSubscription = 0xCE;
    static const char Message_UpdatePersistentSubscriptionCompleted = 0xCF;

    static const char Message_ScavengeDatabase = 0xD0;
    static const char Message_ScavengeDatabaseCompleted = 0xD1;

    static const char Respose_BadRequest = 0xF0;
    static const char Response_NotHandled = 0xF1;
    static const char Response_Authenticate = 0xF2;
    static const char Response_Authenticated = 0xF3;
    static const char Response_NotAuthenticated = 0xF4;

    #endif