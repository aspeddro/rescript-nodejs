module Socket = {
  type kind = [ Stream.duplex | `Socket ];
  type t = Stream.t(Buffer.t, [ Stream.duplex | `Socket]);

  [@bs.module "net"] [@bs.new] external make: unit => t = "Socket";

  module Impl = {
    include Stream.Duplex.Impl;
    type address = {
      [@bs.as "port"] port: int,
      [@bs.as "family"] family: string,
      [@bs.as "address"] address: string,
    };
    [@bs.send] external address: Stream.t('data, [> kind ]) => address = "address";
    [@bs.get] external bufferSize: Stream.t('data, [> kind ]) => int = "bufferSize";
    [@bs.get] external bytesRead: Stream.t('data, [> kind ]) => int = "bytesRead";
    [@bs.get] external bytesWritten: Stream.t('data, [> kind ]) => int = "bytesWritten";
    [@bs.get] external remoteAddress: Stream.t('data, [> kind ]) => string = "remoteAddress";
    [@bs.get] external remoteFamily: Stream.t('data, [> kind ]) => string = "remoteFamily";
    [@bs.get] external remotePort: Stream.t('data, [> kind ]) => int = "remotePort";
  };

  include Impl;

};

module Server = {
  type t;
};

[@bs.module "net"] [@bs.val] external isIP: string => bool = "isIP";
[@bs.module "net"] [@bs.val] external isIPv4: string => bool = "isIPv4";
[@bs.module "net"] [@bs.val] external isIPv6: string => bool = "isIPv6";